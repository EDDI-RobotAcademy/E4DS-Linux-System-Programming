#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUDDY_PAGE_SIZE				4096

int main(int argc, char **argv)
{
	int fd;
	ssize_t nread;
	char buf[BUDDY_PAGE_SIZE] = "test\n";

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
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

	close(fd);

	return 0;
}
