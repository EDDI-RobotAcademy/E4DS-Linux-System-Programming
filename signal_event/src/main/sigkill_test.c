#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("kill -9 pid\n");

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGKILL, SIG_IGN);
	pause();

	return 0;
}
