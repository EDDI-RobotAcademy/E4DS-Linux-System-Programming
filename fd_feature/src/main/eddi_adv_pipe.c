#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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

	fcntl(0, F_SETFL, O_NONBLOCK);
	fcntl(fd, F_SETFL, O_NONBLOCK);

	for (;;)
	{
		if ((ret = read(0, buf, sizeof(buf))) > 0)
		{
			buf[ret - 1] = 0;
			printf("Keyboard Input: [%s]\n", buf);
		}

		if ((ret = read(fd, buf, sizeof(buf))) > 0)
		{
			buf[ret - 1] = 0;
			printf("Pipe Input: [%s]\n", buf);
		}

		if (!strncmp(&buf[0], "q", 1))
		{
			break;
		}
	}

	close(fd);

	return 0;
}
