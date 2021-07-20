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
		return WEXITSTATUS(status);
	}
	else if (pid == 0)
	{
		if (execve("/bin/sh", argv, envp) < 0)
		{
			return 127;
		}
	}
	else
	{
		return -1;
	}
}

int main(void)
{
	int ret;

	ret = my_system("date");

	if (ret < 0)
	{
		printf("fork() error\n");
	}
	else if (ret == 127)
	{
		printf("execve() error\n");
	}
	else
	{
		printf("exit %d\n", ret);
	}

	printf("after\n");

	return 0;
}
