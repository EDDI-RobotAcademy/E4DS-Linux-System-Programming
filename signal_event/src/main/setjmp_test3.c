#include <setjmp.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

jmp_buf env;

void test(void)
{
	srand(time(NULL));

	int num = rand() % 3;

	switch(num)
	{
		case 0:
			printf("file error\n");
			longjmp(env, 1);
			break;
		case 1:
			printf("memory error\n");
			longjmp(env, 2);
			break;
		case 2:
			printf("i/o error\n");
			longjmp(env, 3);
			break;
	}
}

int main(void)
{
	int ret;

	if ((ret = setjmp(env)) == 0)
	{
		test();
	}
	else if (ret > 0)
	{
		printf("error\n");
	}

	printf("ret = %d\n", ret);

	return 0;
}
