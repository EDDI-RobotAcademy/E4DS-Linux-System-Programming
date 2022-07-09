#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUDDY_PAGE_SIZE			4096

int main(int argc, char **argv)
{
	int fd, ret;
	char buf[BUDDY_PAGE_SIZE];

	mkfifo("myfifo", 0755);

	printf("input terminal to cat > myfifo");

	if ((fd = open("myfifo", O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1)
    {
        exit(1);
    }

	for (;;)
	{
		ret = read(0, buf, sizeof(buf));
		buf[ret - 1] = 0;
		printf("Keyboard Input: [%s]\n", buf);

		if (!strncmp(&buf[0], "q", 1))
		{
			break;
		}

		memset(buf, 0x0, ret);

		ret = read(fd, buf, sizeof(buf));
		buf[ret - 1] = 0;
		printf("Pipe Input: [%s]\n", buf);

		if (!strncmp(&buf[0], "q", 1))
		{
			break;
		}

		memset(buf, 0x0, ret);
	}

	close(fd);

	return 0;
}
