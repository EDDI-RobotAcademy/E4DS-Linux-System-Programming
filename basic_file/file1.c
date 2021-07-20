#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define SLAB_CACHE			64
#define ERROR				-1

int main(void)
{
	int fd;
	fd = open("file_test.txt", O_CREAT | O_RDWR, 0644);

	if (fd == ERROR)
	{
		printf("File open() Error\n");
		return -1;
	}

	close(fd);

	return 0;
}
