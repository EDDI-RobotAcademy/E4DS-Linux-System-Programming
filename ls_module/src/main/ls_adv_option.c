#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	DIR *dp;
	int i = 0, cmd, flag = 0;
	struct dirent *p;

	while ((cmd = getopt(argc, argv, "alR")) > 0)
	{
		switch(cmd)
		{
			case 'a':
				printf("a option\n");
				flag |= 1;
				break;
			case 'l':
				printf("l option\n");
				flag |= 2;
				break;
			case 'R':
				printf("R option\n");
				flag |= 4;
				break;
			default:
				printf("unknown option\n");
				break;
		}
	}

	dp = opendir(".");

	while (p = readdir(dp))
	{
		if (!(flag & 1))
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

	if (i % 5 != 0)
	{
		printf("\n");
	}

	closedir(dp);

	return 0;
}
