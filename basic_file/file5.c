#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define BUDDY_PAGE_SIZE						4096
#define SLAB_CACHE							64
#define ERROR								-1

int main(void)
{
	off_t newpos;
	int fd, buf_len;
	ssize_t nread, nwrite;
	char buf[BUDDY_PAGE_SIZE] = "test\n";

	if ((fd = open("file_test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644)) == ERROR)
	{
		printf("open error!\n");
		exit(1);
	}

	if (nwrite = write(fd, buf, sizeof(buf)) == ERROR)
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
