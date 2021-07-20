#include "ipc/semaphore.h"

int create_sem(key_t semkey)
{
	int status = 0, semid;

	if ((semid = semget(semkey, 1, SEMPERM | IPC_CREAT | IPC_EXCL)) == -1)
	{
		if (errno == EEXIST)
		{
			semid = semget(semkey, 1, 0);
		}
	}
	else
	{
		status = semctl(semid, 0, SETVAL, 2);
	}

	if (semid == -1 || status == -1)
	{
		return -1;
	}

	return semid;
}

int consumer(int semid)
{
	struct sembuf p_buf = { 0, -1, SEM_UNDO };

	if (semop(semid, &p_buf, 1) == -1)
	{
		return -1;
	}

	return 0;
}

int producer(int semid)
{
	struct sembuf p_buf = { 0, 1, SEM_UNDO };

	if (semop(semid, &p_buf, 1) == -1)
	{
		return -1;
	}

	return 0;
}
