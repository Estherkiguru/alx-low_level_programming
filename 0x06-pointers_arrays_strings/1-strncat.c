#include "main.h"

/**
 * _strncat - Concatenates two strings with a specified
		maximum number of characters.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * @n: Maximum number of characters to concatenate.
 * Return: Pointer to the resulting string.
 */
char *_strncat(char *dest, char *src, int n)
{
int dest_len = 0;
int i = 0;

while (dest[dest_len] != '\0')
{
dest_len++;
}

while (src[i] != '\0' && i < n)
{
dest[dest_len + i] = src[i];
i++;
}

dest[dest_len + i] = '\0';

return (dest);
}

