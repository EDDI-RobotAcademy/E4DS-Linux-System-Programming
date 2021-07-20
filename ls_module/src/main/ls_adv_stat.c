#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char **argv)
{
	struct stat buf;
	struct passwd *pw;
	struct group *gr;
	struct tm *tm;

	char perm[11] = "----------";
	char rwx[4] = "rwx";
	char ch;

	int i;

	if (argc != 2)
	{
		printf("사용법: 분석할파일명");
		return 0;
	}

	stat(argv[1], &buf);

	if (S_ISDIR(buf.st_mode))
		ch = 'd';
	else if (S_ISREG(buf.st_mode))
		ch = '-';
	else if (S_ISFIFO(buf.st_mode))
		ch = 'p';
	else if (S_ISLNK(buf.st_mode))
		ch = 'l';
	else if (S_ISSOCK(buf.st_mode))
		ch = 's';
	else if (S_ISCHR(buf.st_mode))
		ch = 'c';
	else if (S_ISBLK(buf.st_mode))
		ch = 'b';

	for (i = 0; i < 9; i++)
	{
		if ((buf.st_mode >> (8 - i)) & 1)
		{
			perm[i + 1] = rwx[i % 3];
		}
	}

	printf("%s ", perm);
	printf("%ld ", buf.st_nlink);
	pw = getpwuid(buf.st_uid);
	printf("%s ", pw->pw_name);
	gr = getgrgid(buf.st_gid);
	printf("%s ", gr->gr_name);
	printf("%ld ", buf.st_size);

	tm = localtime(&buf.st_mtime);
	printf("%d-%02d-%02d %02d:%02d:%02d",
			tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
			tm->tm_hour, tm->tm_min, tm->tm_sec);

	printf("\n");

	return 0;
}
