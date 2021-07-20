#include "ipc/shared_memory.h"

int create_shm(long key)
{
	return shmget(key, sizeof(shm_t), IPC_CREAT | 0777);
}

int open_shm(long key)
{
	return shmget(key, sizeof(shm_t), 0);
}

shm_t *get_ptr_shm(int shmid)
{
	return (shm_t *)shmat(shmid, (char *)0, 0);
}

int free_ptr_shm(shm_t *shm_ptr)
{
	return shmdt((char *)shm_ptr);
}
