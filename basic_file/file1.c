#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define SLAB_CACHE			64
#define ERROR				-1

int main(void)
{
	int fd;
	fd = open("file_test.txt", O_CREAT | O_RDWR, 0644);

	if (fd == ERROR)
	{
		printf("File open() Error\n");
		return -1;
	}

	close(fd);

	return 0;
}

// Q: 만약 윈도우에서 유사한 코드를 작성하고자 한다면 ?
// A: Windows API에 기반하여 코드를 수정해야함
//    추가적으로 코드 형태는 아래와 같음
// #ifdef __LINUX_MAC__
//   open() ~~~
// #elif __WINDOWS__
//   WinAPIOpen() // <<<-- API명 요거 아님
// #endif
