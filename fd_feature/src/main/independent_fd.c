#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int ret, fd[2] = { 0 };
	char buf[BUDDY_PAGE_SIZE];

	if ((fd[0] = open("test.txt", O_RDONLY)) == -1)
    {
        exit(1);
    }

	while (ret = read(fd[0], buf, sizeof(buf)))
	{
		write(1, buf, 10);
	}

	if ((fd[1] = open("test.txt", O_RDONLY)) == -1)
    {
        exit(1);
    }

	while (ret = read(fd[1], buf, sizeof(buf)))
	{
		write(1, buf, 10);
	}

    close(fd[0]);
    close(fd[1]);

	return 0;
}
