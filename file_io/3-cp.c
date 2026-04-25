#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * close_fd - closes a file descriptor
 * @fd: file descriptor to close
 * @name: name of file
 */
void close_fd(int fd, char *name)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		(void)name;
		exit(100);
	}
}

/**
 * main - copies content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from;
	int fd_to;
	char buf[1024];
	ssize_t r;
	ssize_t w;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_fd(fd_from, argv[1]);
		exit(99);
	}
	while ((r = read(fd_from, buf, 1024)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_fd(fd_from, argv[1]);
			close_fd(fd_to, argv[2]);
			exit(99);
		}
	}
	close_fd(fd_from, argv[1]);
	close_fd(fd_to, argv[2]);
	return (0);
}
