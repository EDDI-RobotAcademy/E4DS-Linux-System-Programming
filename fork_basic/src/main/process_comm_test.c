#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "file/file.h"

int main(void)
{
	int fd, ret;
	char buf[SLAB_CACHE];
	pid_t pid;

	mkfifo("myfifo", 0755);
    printf("input terminal to cat > myfifo\n");

	new_file_control_manager();

	if (file_error(fd = alloc_fd_with_file_rw("myfifo")))
    {
        printf("open error!\n");
        exit(1);
    }

	if ((pid = fork()) > 0)
	{
		for (;;)
		{
			ret = file_read(0, buf, sizeof(buf));
			buf[ret] = 0;
			printf("Keyboard: %s\n", buf);
		}
	}
	else if (pid == 0)
	{
		for (;;)
		{
			ret = read(fd, buf, sizeof(buf));
			buf[ret] = 0;
			printf("myfifo: %s\n", buf);
		}
	}
	else
	{
		perror("fork() ");
		exit(-1);
	}

	file_close(fd);

	return 0;
}
