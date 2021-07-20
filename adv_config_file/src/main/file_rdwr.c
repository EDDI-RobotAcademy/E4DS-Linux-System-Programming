#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUDDY_PAGE_SIZE				4096

int main(int argc, char **argv)
{
	int fd;
	ssize_t nread, nwrite;
	char buf[BUDDY_PAGE_SIZE] = "test\n";

	if (argc != 2)
	{
		printf("사용법: 파일명\n");
		exit(-1);
	}

	if ((fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1)
    {
        printf("open error!\n");
        exit(1);
    }

    if (nwrite = write(fd, buf, sizeof(buf)) == -1)
    {
        printf("write error!\n");
    }

    printf("fd = %d, buf = %s", fd, buf);

    lseek(fd, (off_t)0, SEEK_SET);

    while ((nread = read(fd, buf, BUDDY_PAGE_SIZE)) > 0)
    {
        printf("nread = %ld\n", nread);

        if (write(1, buf, nread) < nread)
        {
            printf("print error\n");
            close(fd);
        }
    }

    close(fd);

	return 0;
}
