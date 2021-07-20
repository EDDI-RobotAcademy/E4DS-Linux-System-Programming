#include <setjmp.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

jmp_buf env;

void test2(void)
{
	longjmp(env, 1);
}

void test(void)
{
	printf("call test\n");
	test2();
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

	return 0;
}
