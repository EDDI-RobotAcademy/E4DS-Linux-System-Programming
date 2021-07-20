#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUDDY_PAGE_SIZE			4096

int main(int argc, char **argv)
{
	int fd, buf_len;
	ssize_t nwrite;
	char buf[BUDDY_PAGE_SIZE] = "test\n";

	if (argc != 2)
	{
		printf("사용법: 파일명\n");
	}

	if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		exit(1);
	}

	buf_len = strlen(buf);
    nwrite = write(fd, buf, buf_len);
    if (nwrite != buf_len)
    {
        printf("write error!\n");
        exit(2);
    }

	close(fd);

	return 0;
}
