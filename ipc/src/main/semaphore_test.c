#include "ipc/semaphore.h"

int main(void)
{
	int sid;
	sid = create_sem(0x777);

	printf("before\n");

	producer(sid);

	printf("Enter Critical Section\n");

	getchar();

	consumer(sid);

	printf("after\n");

	return 0;
}
