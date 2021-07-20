#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

void term_status(int status)
{
	if (WIFEXITED(status))
	{
		printf("(exit)status: 0x%x\n", WEXITSTATUS(status));
	}
	else if (WTERMSIG(status))
	{
		printf("(signal)status: 0x%x, %s\n",
			status & 0x7f, WCOREDUMP(status) ? "core dumped" : "");
	}
}

void my_sig(int signo)
{
	int status;

	while(wait(&status) > 0)
	{
		term_status(status);
	}
}

int main(void)
{
	pid_t pid;
	int i;

	signal(SIGCHLD, my_sig);

	if ((pid = fork()) > 0)
	{
		for(i = 0; i < 10000; i++)
		{
			usleep(50000);
			printf("%d\n", i + 1);
		}
	}
	else if (pid == 0)
	{
		sleep(5);
	}
	else
	{
		perror("fork() ");
		exit(-1);
	}

	return 0;
}
