#include "file/file.h"

int file_open_create(char *name)
{
	int fd = open(name, O_CREAT | O_RDWR, 0644);
	return fd;
}

void opened_file_close(int fd)
{
	close(fd);
}

bool is_fd_error(int fd)
{
	if (fd == -1)
	{
		return true;
	}

	return false;
}

int get_fd_num(FileControlManager *fcm)
{
	return fcm->used_fd_num;
}

void alloc_fd(int idx, int fd)
{
	fcm->fc[idx].fd = fd;
}

int readonly_create(char *name)
{
	return open(name, O_RDONLY);
}

int writeonly_create(char *name)
{
	return open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

int read_write_create(char *name)
{
    return open(name, O_RDWR | O_CREAT | O_TRUNC, 0644);
}

int write_buf2file(int fd, char *buf, int buf_len)
{
	return write(fd, buf, buf_len);
}

int read_file2buf(int fd, char *buf, int buf_len)
{
	return read(fd, buf, buf_len);
}

int seeking_file(int fd, off_t offset, int whence)
{
	return lseek(fd, offset, whence);
}

void new_file_control_manager(void)
{
	fcm = (FileControlManager *)malloc(sizeof(FileControlManager));

	fcm->fc = (FileControl *)malloc(sizeof(FileControl) * SLAB_CACHE);

	fcm->file_create = file_open_create;
	fcm->file_close = opened_file_close;
	fcm->file_error = is_fd_error;
	fcm->file_count_fd_num = get_fd_num;
	fcm->file_alloc_fd = alloc_fd;
	fcm->file_readonly_create = readonly_create;
	fcm->file_writeonly_create = writeonly_create;
	fcm->file_read_write_create = read_write_create;
	fcm->file_write = write_buf2file;
	fcm->file_read = read_file2buf;
	fcm->file_lseek = seeking_file;

	fcm->used_fd_num = 0;
}

int alloc_fd_with_file_create(char *name)
{
	int fd, idx = file_get_fd_num();

	fd = file_create(name);
	file_alloc_fd(idx, fd);
	//fcm->file_alloc_fd(idx, fd);

	return fd;
}

int alloc_fd_with_file_write(char *name)
{
	int fd, idx = file_get_fd_num();

	fd = file_writeonly_create(name);
	file_alloc_fd(idx, fd);

	return fd;
}

int alloc_fd_with_file_read(char *name)
{
	int fd, idx = file_get_fd_num();

	fd = file_readonly_create(name);
	file_alloc_fd(idx, fd);

	return fd;
}

int alloc_fd_with_file_rw(char *name)
{
    int fd, idx = file_get_fd_num();

    fd = file_read_write_create(name);
    file_alloc_fd(idx,fd);

    return fd;
}

