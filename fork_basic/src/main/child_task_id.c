#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
	pid_t pid;
	pid = fork();

	if (pid > 0)
	{
		printf("parent: pid = %d, cpid = %d\n", getpid(), pid);
	}
	else if (pid == 0)
	{
		printf("child: pid = %d, cpid = %d\n", getpid(), pid);
	}
	else
	{
		perror("fork() ");
		exit(-1);
	}

	return 0;
}
