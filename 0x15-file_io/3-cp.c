#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: An array of arguments.
 * Return: 0 on success, or an error code on failure.
 * handle_error - Handle and print error message,
 * then exit with the given code.
 * @message: The error message to print.
 * @exit_code: The exit code to use when exiting the program.
 */

void handle_error(const char *message, int exit_code)
{
	dprintf(2, "%s\n", message);
	exit(exit_code);
}

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t rd, wr;
	char buffer[1024];

	if (argc != 3)
	{
		handle_error("Usage: cp file_from file_to", 97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		handle_error("Error: Can't read from file", 98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		handle_error("Error: Can't write to file", 99);
	}

	while ((rd = read(fd_from, buffer, 1024)) > 0)
	{
		wr = write(fd_to, buffer, rd);
		if (wr != rd)
		{
			handle_error("Error: Can't write to file", 99);
		}
	}
	if (rd == -1)
	{
		handle_error("Error: Can't read from file", 98);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		handle_error("Error: Can't close file descriptor", 100);
	}

	return (0);
}

