#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *task1(void *x)
{
	int count;
	int *tmp;
	tmp = x;

	for (count = 1; count < *tmp; count++)
	{
		printf("Work from threadA: %d * 2 = %d\n", count, count * 2);
	}

	printf("Thread A\n");
}

void *task2(void *x)
{
	int count;
	int *tmp;
	tmp = x;

	for (count = 1; count < *tmp; count++)
	{
		printf("Work from threadB: %d + 2 = %d\n", count, count + 2);
	}

	printf("Thread B\n");
}

int main(int argc, char **argv)
{
	pthread_attr_t detached_attr;
	pthread_t A, B;
	int num;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num = atoi(argv[1]);

	pthread_attr_init(&detached_attr);
	pthread_attr_setdetachstate(&detached_attr, PTHREAD_CREATE_DETACHED);

	pthread_create(&A, NULL, task1, &num);
	pthread_create(&B, &detached_attr, task2, &num);

	printf("Waiting for Threads to Join\n");

	pthread_join(A, NULL);

	return 0;
}
