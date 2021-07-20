#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void print_str(const char *str)
{
	while(*str != '\0')
	{
		putchar(*str++);
		fflush(stdout);
		usleep(50);
	}
}

int main(void)
{
	if(fork() == 0)
		print_str("--------------");
	else
		print_str("++++++++++++++");

	printf("\n");

	return 0;
}
