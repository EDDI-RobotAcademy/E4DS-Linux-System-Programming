#include "ipc/msg_queue.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

int cli_info[100];
int count = 0;

int main(void)
{
	int qid, i;
	msg_queue_t msg;
	long mtype;

	qid = create_mq(5000);

	if (qid < 0)
	{
		printf("q open fail: %d\n", errno);
		return -1;
	}

	while (1)
	{
		mtype = recv_mq(qid, 1L, &msg);

		for (i = 0; i < count; i++)
		{
			if (cli_info[i] == mtype)
			{
				break;
			}
		}

		if (i == count)
		{
			printf("새로운 사용자 접속, 현재 접속자수: %d\n", count + 1);
			cli_info[count++] = mtype;
		}

		if (mtype > 0)
		{
			int len = strlen(msg.mtext);
			
			if (!strcmp(&msg.mtext[len - 4], "exit"))
			{
				printf("사용자 나감, 현재 접속자수: %d\n", count - 1);
				for (i = 0; i < count; i++)
				{
					if (cli_info[i] == mtype)
					{
						break;
					}
				}

				cli_info[i] = cli_info[--count];
			}
			else
			{
				printf("recv: %s\n", msg.mtext);

				for (i = 0; i < count; i++)
				{
					if (send_mq(qid, cli_info[i], &msg) < 0)
					{
						break;
					}
				}
			}
		}
	}

	remove_mq(qid);

	return 0;
}
