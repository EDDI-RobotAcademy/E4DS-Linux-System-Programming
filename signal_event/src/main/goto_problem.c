#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

#define BUDDY_PAGE_SIZE				4096

// BUDDY_FOR_TRIPPLE_ARRAY
#define BFTA						(BUDDY_PAGE_SIZE >> 8)
#define ONE_BYTE					1
#define ERROR						-1

void test(void)
{
	goto err;
}

int main(void)
{
	int i, j, k, ret, flag = 0, cnt = 0;
	char tensor[BFTA][BFTA][BFTA] = { 0 };

	srand(time(NULL));

	tensor[rand() % BFTA][rand() % BFTA][rand() % BFTA] = ERROR;

	printf("아래는 딥러닝에 활용되는 행렬 연산이라 가정\n");

	for (i = 0; i < BFTA; i++)
	{
		for (j = 0; j < BFTA; j++)
		{
			for (k = 0; k < BFTA; k++)
			{
				cnt++;

				printf("cnt = %d\n", cnt);

				if (tensor[i][j][k] == ERROR)
				{
					printf("Error Accurance\n");
					sleep(3);

					test();
				}
			}
		}
	}

	printf("매 루프에서 검사하는 루틴이 사라짐\n");

	return 0;

err_handler:
	printf("에러를 핸들링합니다.\n");

	return -1;
}
