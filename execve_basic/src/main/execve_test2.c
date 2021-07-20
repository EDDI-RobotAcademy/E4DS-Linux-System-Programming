#include <unistd.h>
#include <stdio.h>

int main(void)
{
	execlp("ps", "ps", "-e", "-f", 0);
	printf("after\n");

	return 0;
}
