#ifndef __MSG_QUEUE_H__
#define __MSG_QUEUE_H__

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

typedef struct msg_queue
{
	long to_mtype;
	long fm_mtype;
	char mtext[100];
}
msg_queue_t;

int create_mq(long key);
int open_mq(long key);
long send_mq(int qid, long mtype, msg_queue_t *msg);
long recv_mq(int qid, long mtype, msg_queue_t *msg);
int get_free_size_mq(int qid, long *freesize);
int remove_mq(int qid);

#endif
