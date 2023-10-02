#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - Read and print the content of a text file.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters
 * read and printed, or 0 on error.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t num_read;
ssize_t num_written;
char buffer[1024];

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	num_read = read(fd, buffer, letters);
	if (num_read == -1)
	{
		close(fd);
		return (0);
	}
num_written = write(STDOUT_FILENO, buffer, num_read);
	close(fd);
	if (num_written == num_read)
		return (num_read);

	return (0);
}
