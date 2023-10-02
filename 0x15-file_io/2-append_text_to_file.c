#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * append_text_to_file - Append text to the end of a file.
 * @filename: The name of the file to which text will be appended.
 * @text_content: The text content to append.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t num_written;

	if (filename == NULL)
		return (-1);

fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0600);
if (fd == -1)
	return (-1);

if (text_content != NULL)
{
num_written = write(fd, text_content, strlen(text_content));
	if (num_written == -1)
{
	close(fd);
	return (-1);
}
}
close(fd);

return (1);
}

