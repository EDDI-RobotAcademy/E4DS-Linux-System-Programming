#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
		printf("argv[%d] = [%s]\n", i, argv[i]);
	}

	for (i = 0; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}

	return 0;
}
