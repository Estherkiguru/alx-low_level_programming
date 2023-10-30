#include "main.h"

/**
 * read_textfile - Reads and prints the contents of a
 * text file to the standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 * Return: The actual number of letters read and printed. Returns 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_written;
	char buffer[1024];

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	n_read = read(fd, buffer, sizeof(buffer));
	if (n_read == -1)
	{
		close(fd);
		return (0);
	}

	if (n_read < (ssize_t)letters)
	{
		n_written = write(STDOUT_FILENO, buffer, n_read);
	} else
	{
		n_written = write(STDOUT_FILENO, buffer, letters);
	}

	close(fd);

	if (n_written == -1 || n_written != n_read)
		return (0);

	return (n_written);
}


