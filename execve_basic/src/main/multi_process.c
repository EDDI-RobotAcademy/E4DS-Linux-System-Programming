#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int my_system(char *cmd)
{
	pid_t pid;
	int status;

	char *argv[] = {"sh", "-c", cmd, 0};
	char *envp[] = {0};

	if ((pid = fork()) > 0)
	{
		wait(&status);
	}
	else if (pid == 0)
	{
		execve("/bin/sh", argv, envp);
	}
}

int main(void)
{
	my_system("date");
	printf("after\n");

	return 0;
}
