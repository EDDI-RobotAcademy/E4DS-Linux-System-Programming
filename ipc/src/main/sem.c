#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <semaphore.h>

static int semid;

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
	sem_t *sem_id = NULL;

	sem_id = sem_open("order", O_CREAT, 0777, 1);
	sem_unlink("order");

	if(fork() == 0)
	{
		//printf("parent sem_id = %d\n", sem_id);
		sem_wait(sem_id);
		print_str("--------------\n");
		sem_post(sem_id);
		//sleep(1);
	}
	else
	{
		//sem_id = semget("order", 1, IPC_CREAT | 0777);
		//sem_id = sem_open("order", 0, 0777, 0);
		//printf("child sem_id = %d\n", sem_id);
		usleep(100);
		sem_wait(sem_id);
		print_str("++++++++++++++\n");
		sem_post(sem_id);
	}

	sem_close(sem_id);

	return 0;
}
