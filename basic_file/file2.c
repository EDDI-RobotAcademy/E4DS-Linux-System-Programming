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
	ssize_t nwrite;
	char buf[BUDDY_PAGE_SIZE] = "test\n";

	fd = open("file_test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd == ERROR)
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
