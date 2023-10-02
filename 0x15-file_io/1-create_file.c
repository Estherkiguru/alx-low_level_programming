#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * create_file - Create a file with specified content.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file (can be NULL).
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t num_written;

	if (filename == NULL)
		return (-1);

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
if (text_content != NULL)
{
num_written = write(fd, text_content, strlen(text_content));
if (num_written == -1 || (size_t)num_written != strlen(text_content))
{
	close(fd);
	return (-1);
}
}

close(fd);

return (1);
}

