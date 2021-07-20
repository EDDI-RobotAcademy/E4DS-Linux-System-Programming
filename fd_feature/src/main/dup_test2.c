#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int ret, fd;
	char buf[BUDDY_PAGE_SIZE] = "입력을 리다이렉션 합니다.";

	if ((fd = open("dup.txt", O_RDONLY)) == -1)
    {
        exit(1);
    }

	close(0);
	dup(fd);

	puts(buf);

	close(fd);

	return 0;
}
