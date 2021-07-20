#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	DIR *dp;
	int i;
	struct dirent *p;

	dp = opendir(".");

	while (p = readdir(dp))
	{
		if (p->d_name[0] == '.')
		{
			continue;
		}

		printf("%-16s ", p->d_name);

		if ((i + 1) % 5 == 0)
		{
			printf("\n");
		}

		i++;
	}

	printf("\n");

	closedir(dp);

	return 0;
}
