#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUDDY_PAGE_SIZE			4096

int main(int argc, char **argv)
{
	int ret, fd;
	char buf[BUDDY_PAGE_SIZE] = "입력을 리다이렉션 합니다.";

	if ((fd = open("dup.txt", O_RDWR)) == -1)
    {
        exit(1);
    }

#if 1
	close(0);
	dup(fd);
	read(fd, buf, sizeof(buf));
#endif

	printf("buf = %s", buf);

	close(fd);

	return 0;
}
