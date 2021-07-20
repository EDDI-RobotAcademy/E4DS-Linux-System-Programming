#include "ipc/msg_queue.h"

int create_mq(long key)
{
	return msgget(key, IPC_CREAT | 0777);
}

int open_mq(long key)
{
	return msgget(key, 0);
}

long send_mq(int qid, long mtype, msg_queue_t *msg)
{
	int st;
	msg->to_mtype = mtype;
	msg->fm_mtype = getpid();

	st = msgsnd(qid, msg, (sizeof(msg_queue_t) - sizeof(long)), IPC_NOWAIT);

	if (st < 0)
	{
		return -1L;
	}

	return msg->fm_mtype;
}

long recv_mq(int qid, long mtype, msg_queue_t *msg)
{
	int st;

	st = msgrcv(qid, msg, sizeof(msg_queue_t) - sizeof(long), mtype, 0);

	if (st < 0)
	{
		return -1L;
	}

	return msg->fm_mtype;
}

int get_free_size_mq(int qid, long *freesize)
{
	int rtn;
	struct msqid_ds stat_q;

	if (qid < 0)
	{
		return -1;
	}

	rtn = msgctl(qid, IPC_STAT, &stat_q);

	if (rtn < 0)
	{
		return -1;
	}

	*freesize = stat_q.msg_qbytes - stat_q.msg_cbytes;

	return rtn;
}

int remove_mq(int qid)
{
	return msgctl(qid, IPC_RMID, 0);
}
