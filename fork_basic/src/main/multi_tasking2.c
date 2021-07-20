#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;
	int i;

	pid = fork();

	if (pid > 0)
	{
		for (;;)
		{
			for (i = 0; i < 26; i++)
			{
				printf("%c ", i + 'A');
				fflush(stdout);
			}
		}
	}
	else if (pid == 0)
	{
		for (;;)
		{
			for (i = 0; i < 26; i++)
			{
				printf("%c ", i + 'a');
				fflush(stdout);
			}
		}
	}
	else
	{
		perror("fork() ");
		exit(-1);
	}

	printf("\n");

	return 0;
}
