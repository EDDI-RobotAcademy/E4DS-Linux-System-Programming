#include "ipc/shared_memory.h"

int main(void)
{
	int mid;
	shm_t *p;

	mid = create_shm(0x333);

	p = get_ptr_shm(mid);

	printf("이름: [%s], 점수: [%d]\n", p->name, p->score);

	free_ptr_shm(p);

	return 0;
}
