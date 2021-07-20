#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int ret, fd;
	char buf[BUDDY_PAGE_SIZE];

	if ((fd = open("dup.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    {
        exit(1);
    }

	close(1);
	dup(fd);

	printf("이 글자의 행방은 어디로 갔는가 ?\n");

	close(fd);

	return 0;
}
