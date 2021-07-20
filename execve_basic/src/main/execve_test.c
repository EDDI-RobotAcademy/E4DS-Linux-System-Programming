#include <unistd.h>

int main(void)
{
	execlp("ps", "ps", "-e", "-f", 0);

	return 0;
}
