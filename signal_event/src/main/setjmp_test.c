#include <setjmp.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

jmp_buf env;

void test(void)
{
	printf("void test(void)\n");
	longjmp(env, 1);
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
