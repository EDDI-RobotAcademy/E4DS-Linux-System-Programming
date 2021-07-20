#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	struct stat buf;
	char ch;

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

	printf("%c\n", ch);

	return 0;
}
