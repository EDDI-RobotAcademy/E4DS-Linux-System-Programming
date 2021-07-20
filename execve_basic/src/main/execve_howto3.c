#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int status;
	pid_t pid;

	char *argv[] = {"./newpgm2", "newpgm2", "one", "two", "three", 0};
	char *env[] = {"name = EDDI", "full = Electric Design Development Institute", 0};

	if ((pid = fork()) > 0)
	{
		wait(&status);
		printf("prompt >\n");
	}
	else if (pid == 0)
	{
		execve("./newpgm2", argv, env);
	}

	return 0;
}
