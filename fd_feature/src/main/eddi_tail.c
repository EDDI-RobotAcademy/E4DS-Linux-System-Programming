#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char ch;
	int line = 0, fd;

	if (argc != -2)
	{
		printf("사용법: 파일명\n");
		exit(-1);
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        exit(1);
    }

	while (read(fd, &ch, 1))
	{
		if (ch == '\n')
		{
			line++;
		}

		write(1, &ch, 1);

		if (line == 10)
		{
			break;
		}
	}

	close(fd);

	return 0;
}
