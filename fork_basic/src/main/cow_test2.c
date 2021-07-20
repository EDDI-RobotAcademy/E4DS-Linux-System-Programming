#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int global = 100;

int main(void)
{
	int local = 10;
	pid_t pid;
	int i;

	pid = fork();

	if (pid > 0)
	{
		global++;
		local++;
		printf("global: %d, local: %d\n", global, local);
	}
	else if (pid == 0)
	{
		printf("global: %d, local: %d\n", global, local);
	}
	else
	{
		perror("fork() ");
		exit(-1);
	}

	printf("\n");

	return 0;
}
