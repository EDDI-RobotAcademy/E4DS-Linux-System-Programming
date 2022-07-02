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
	int fd, buf_len;
	ssize_t nread;
	char buf[BUDDY_PAGE_SIZE] = "";

	fd = open("file_test.txt", O_RDONLY);

	if (fd == ERROR)
	{
		exit(1);
	}

	nread = read(fd, buf, sizeof(buf));
	printf("buf = %s", buf);

	close(fd);

	return 0;
}
