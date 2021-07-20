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
	ssize_t nread;
	char buf[BUDDY_PAGE_SIZE] = "test\n";

	fd = open("file_test.txt", O_RDONLY);

	if (fd == ERROR)
	{
		exit(1);
	}

	while ((nread = read(fd, buf, BUDDY_PAGE_SIZE)) > 0)
	{
		if (write(1, buf, nread) < nread)
		{
			close(fd);
		}
	}

	lseek(fd, (off_t)0, SEEK_SET);
	newpos = lseek(fd, (off_t)0, SEEK_END);
	printf("file size = %ld\n", newpos);

	close(fd);

	return 0;
}
