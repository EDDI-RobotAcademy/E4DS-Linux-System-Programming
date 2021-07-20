#include "ipc/msg_queue.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int qid, st, ret, len, status;
	char buf[1024];
	msg_queue_t msg;

	if (argc != 2)
	{
		printf("사용법: 닉네임\n");
		exit(-1);
	}

	len = strlen(argv[1]);

	qid = open_mq(5000);

	if (qid < 0)
	{
		printf("q open fail: %d\n", errno);
		return -1;
	}

	if ((ret = fork()) > 0)
	{
		for (;;)
		{
			int nread;

			memset(msg.mtext, '\0', 100);
			nread = read(0, buf, sizeof(buf));
			buf[nread - 1] = '\0';
			// gets(buf);
			sprintf(msg.mtext, "[%s]:", argv[1]);
			strcat(msg.mtext, buf);


			if (send_mq(qid, 1L, &msg) <= 0)
			{
				printf("q send fail: %d\n", errno);
				break;
			}

			if (!strcmp(&msg.mtext[len + 3], "exit"))
			{
				printf("Client Process Exit\n");
				kill(ret, 9);
				wait(&status);
				break;
			}
		}
	}
	else
	{
		for (;;)
		{
			st = recv_mq(qid, getpid(), &msg);
			if (st > 0)
			{
				printf("%s\n", msg.mtext);
			}
		}
	}

	return 0;
}
