#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define BUDDY_PAGE_SIZE						4096
#define SLAB_CACHE							64
#define ERROR								-1

typedef struct FileControlManager FileControlManager;
struct FileControlManager
{
	int (* file_create)(char *);
	void (* file_close)(int);
	bool (* file_error)(int);
	int (* file_readonly_create)(char *);
	int (* file_writeonly_create)(char *);
    int (* file_read_write_create)(char *);
	int (* file_write)(int, char *, int);
	int (* file_read)(int, void *, int);
	int (* file_lseek)(int, off_t, int);
};

int file_open_create(char *name);
void opened_file_close(int fd);
bool is_fd_error(int fd);
int readonly_create(char *name);
int writeonly_create(char *name);
int write_buf2file(int fd, char *buf, int buf_len);
int read_file2buf(int fd, void *buf, int buf_len);
int seeking_file(int fd, off_t offset, int whence);

void new_file_control_manager(void);
int alloc_fd_with_file_create(char *name);
int alloc_fd_with_file_write(char *name);
int alloc_fd_with_file_read(char *name);
int alloc_fd_with_file_rw(char *name);

FileControlManager *fcm;

#define file_create(name)													\
({																			\
	fcm->file_create(name);													\
})

#define file_error(fd)														\
({																			\
	fcm->file_error(fd);													\
})

#define file_close(fd)														\
({																			\
	fcm->file_close(fd);													\
})

#define file_writeonly_create(name)											\
({																			\
	fcm->file_writeonly_create(name);										\
})

#define file_readonly_create(name)											\
({																			\
	fcm->file_readonly_create(name);										\
})

#define file_read_write_create(name)                                        \
({                                                                          \
    fcm->file_read_write_create(name);                                      \
})

#define file_write(fd, buf, len)											\
({																			\
	fcm->file_write(fd, buf, len);											\
})

#define file_read(fd, buf, len)												\
({																			\
	fcm->file_read(fd, buf, len);											\
})

#define file_lseek(fd, offset, whence)										\
({																			\
	fcm->file_lseek(fd, offset, whence);									\
})

#endif
