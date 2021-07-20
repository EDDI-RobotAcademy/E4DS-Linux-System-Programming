#include <stdio.h>
#include <sys/time.h>

#define PRECISION		10000000000.0

typedef struct timeval tv;

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

float calc_integral(int start, int end)
{
	int i;
	long double dx = 1 / PRECISION;
	long double area = 0, cur_x = (double)start;
	long double sample_number = calc_sample_number(start, end, dx);
	printf("sample_number = %.10Lf\n", sample_number);

	for (i = 0; cur_x < end; i++, cur_x += dx)
	{
		area += cur_x * cur_x * dx;
	}

	printf("i cnt = %d\n", i);

	return area;
}

int main(void)
{
	float res;
	tv start, end;

	printf("1 ~ 3 까지 x^2에 대한 정적분 계산\n");

	gettimeofday(&start, NULL);

	res = calc_integral(1, 3);
	printf("계산 결과 = %f\n", res);

	gettimeofday(&end, NULL);
	get_runtime(start, end);

	return 0;
}
