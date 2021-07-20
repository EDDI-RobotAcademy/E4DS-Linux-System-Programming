#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	DIR *dp;
	int i, cmd;
	struct dirent *p;

	cmd = getopt(argc, argv, "a");

	dp = opendir(".");

	while (p = readdir(dp))
	{
		if (cmd == 'a')
		{
			;
		}
		else
		{
			if (p->d_name[0] == '.')
			{
				continue;
			}
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
