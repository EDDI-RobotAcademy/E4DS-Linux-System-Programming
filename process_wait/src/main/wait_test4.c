#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;
	int status;

	if ((pid = fork()) > 0)
	{
		wait(&status);

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
	else if (pid == 0)
	{
		abort();
	}
	else
	{
		perror("fork() ");
		exit(-1);
	}

	return 0;
}
