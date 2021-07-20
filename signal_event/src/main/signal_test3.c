#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void my_sig(int signo)
{
	printf("my_sig called\n");
}

int main(void)
{
	signal(SIGINT, my_sig);

	for(;;)
	{
		printf("signal test ......\n");
		sleep(1);
	}

	return 0;
}
