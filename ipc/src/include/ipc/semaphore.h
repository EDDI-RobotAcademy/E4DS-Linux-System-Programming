#ifndef __SEMAPHORE_H__
#define __SEMAPHORE_H__

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define SEMPERM			0777

int create_sem(key_t semkey);
int consumer(int semid);
int producer(int semid);

#endif
