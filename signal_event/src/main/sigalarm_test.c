#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUDDY_PAGE_SIZE			4096

void my_sig(int signo)
{
	printf("동전을 넣으세요!\n");
	exit(0);
}

int main(void)
{
	char buf[BUDDY_PAGE_SIZE];
	int ret;

	signal(SIGALRM, my_sig);
	alarm(3);

	read(0, buf, sizeof(buf));
	alarm(0);

	return 0;
}
