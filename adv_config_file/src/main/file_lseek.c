#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	off_t newpos;

	if (argc != 2)
	{
		printf("사용법: 파일명\n");
		exit(-1);
	}

	fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        exit(1);
    }

    lseek(fd, (off_t)0, SEEK_SET);
    newpos = lseek(fd, (off_t)0, SEEK_END);
    printf("file size = %ld\n", newpos);

    close(fd);

	return 0;
}
