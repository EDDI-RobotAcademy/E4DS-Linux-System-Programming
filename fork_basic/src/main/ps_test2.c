#include <stdio.h>

int main(void)
{
	// ps_test1에서 출력된 주소를 입력
	int *p = 0xbfcccccc;
	printf("&a = %p\n", *p);

	return 0;
}
