#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd, ret;
	char buf[64];

	if (argc != 2)
	{
		printf("사용법: 실행파일명 '보고싶은파일명'\n");
		exit(-1);
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
		printf("open error\n");
        exit(1);
    }

	while (ret = read(fd, buf, sizeof(buf)))
	{
		write(1, buf, ret);
	}

    close(fd);

	return 0;
}
