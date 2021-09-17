#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define PRECISION		1000000000.0

#define THREAD_NUM		5
#define ONE				1

typedef struct timeval tv;

typedef struct _start_end
{
	long double start, end;
}
start_end;

int thread_id = 0;
long double dx = 1 / PRECISION;
long double area[THREAD_NUM];
long double range;

start_end se[THREAD_NUM];

double get_runtime(tv start, tv end)
{
	end.tv_usec = end.tv_usec - start.tv_usec;
	end.tv_sec = end.tv_sec - start.tv_sec;
	end.tv_usec += end.tv_sec * 1000000;

	printf("runtime = %lf sec\n", end.tv_usec / 1000000.0);

	return end.tv_usec / 1000000.0;
}

long double calc_sample_number(int start, int end, float dx)
{
	long double res = (end - start) * PRECISION;
	return res;
}

void *hpc_integral_task(void *x)
{
	int i;
	int id = thread_id++;

	/*
	long double start = se[id].start;
	long double cur_x = start * dx;
	long double end = se[id].end * dx;
	long double tmp = 0;
	*/

	long double start, end, cur_x, tmp = 0;

	start = se[id].start;

	if (id == 0)
	{
		start = ONE;
		end = start + range;
	}
	else
	{
		start = ONE + se[id].start * dx;
		end = start + range;
	}

	cur_x = start;

	printf("id = %d, start = %Lf, end = %Lf, cur_x = %Lf\n", id, start, end, cur_x);

	for (; cur_x < end; cur_x += dx)
	{
		tmp += cur_x * cur_x * dx;
	}

	area[id] = tmp;
}

void init_hpc_integral(long double start, long double end)
{
	int i;
	long long int remain_sample;
	long double total_sample;
	long double increment;

	dx = 1 / PRECISION;

	total_sample = (long double)calc_sample_number(start, end, dx);
	remain_sample = (long long int)total_sample % (long long int)THREAD_NUM;

	printf("total_sample = %Lf\n", total_sample);

	increment = total_sample / THREAD_NUM;

	printf("increment = %Lf\n", increment);

	se[0].start = start;
	se[0].end = start + total_sample / THREAD_NUM;

	range = se[0].end * dx;
	increment = se[0].end - se[0].start;

	printf("start[0] = %Lf, end[0] = %Lf\n", se[0].start, se[0].end);

	for (i = 1; i < THREAD_NUM; i++)
	{
		start += increment;

		se[i].start = start;

		if (!remain_sample)
		{
			se[i].end = start + increment;
		}
		else
		{
			se[i].end = start + increment + ONE;
			remain_sample--;
		}

		printf("start[%d] = %Lf, end[%d] = %Lf\n", i, se[i].start, i, se[i].end);
	}
}

int main(void)
{
	int i;
	long double res = 0;
	tv start, end;
	pthread_t calc_thread[THREAD_NUM];

	printf("1 ~ 3 까지 x^2에 대한 정적분 계산\n");

	gettimeofday(&start, NULL);

	init_hpc_integral(1, 3);

	for (i = 0; i < THREAD_NUM; i++)
	{
		pthread_create(&calc_thread[i], NULL, hpc_integral_task, NULL);
	}

	for (i = 0; i < THREAD_NUM; i++)
	{
		pthread_join(calc_thread[i], NULL);
	}

	for (i = 0; i < THREAD_NUM; i++)
	{
		res += area[i];
		printf("area[%d] = %Lf\n", i, area[i]);
	}

	printf("res = %Lf\n", res);

	gettimeofday(&end, NULL);
	get_runtime(start, end);

	return 0;
}
