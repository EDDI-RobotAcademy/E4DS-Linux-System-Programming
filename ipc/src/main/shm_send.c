#include "ipc/shared_memory.h"

int main(void)
{
	int mid;
	char buf[64] = "테스트";
	shm_t *p;

	mid = open_shm(0x333);

	p = get_ptr_shm(mid);

	strcpy(p->name, buf);
	p->score = 93;
	getchar();

	free_ptr_shm(p);

	return 0;
}
