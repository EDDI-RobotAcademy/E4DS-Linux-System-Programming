#ifndef __SHARED_MEMORY_H__
#define __SHARED_MEMORY_H__

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

typedef struct
{
	char name[20];
	int score;
}
shm_t;

int create_shm(long key);
int open_shm(long key);
shm_t *get_ptr_shm(int shmid);
int free_ptr_shm(shm_t *shm_ptr);

#endif
