#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define CNT			10000

void *task1(void *x)
{
	int old_state;
	int count;

	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_state);

	for (count = 1; count < CNT; count++)
	{
		printf("Thread A - working: %d\n", count);
	}

	printf("Thread A\n");
}

void *task2(void *x)
{
	int old_state;
	int count;

	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &old_state);
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, &old_state);

	for (count = 1; count < CNT; count++)
	{
		printf("Thread B - working: %d\n", count);
	}

	printf("Thread B\n");
}

void *task3(void *x)
{
	int old_state, old_type;
	int count;

	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &old_state);
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &old_state);

	for (count = 1; count < CNT; count++)
	{
		printf("Thread C - working: %d\n", count);

		if ((count % 100) == 0)
		{
			pthread_testcancel();
		}
	}

	printf("Thread C\n");
}

int main(int argc, char **argv)
{
	void (*thread_task_arr[3])(void *) = { task1, task2, task3 };
	pthread_t threads[3];
	void *status;
	int i, count;

	for (i = 0; i < 3; i++)
	{
		pthread_create(&threads[i], NULL, thread_task_arr[i], NULL);
	}

	for (i = 0; i < 3; i++)
	{
		pthread_cancel(threads[i]);
	}

	for (count = 0; count < 3; count++)
	{
		pthread_join(threads[count], &status);

		if (status == PTHREAD_CANCELED)
		{
			printf("thread %d has been canceled\n", count);
		}
		else
		{
			printf("thread %d has survived\n", count);
		}
	}

	return 0;
}
