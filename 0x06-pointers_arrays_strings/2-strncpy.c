#include "main.h"

/**
 * _strncpy - Copies a string up to a specified
		maximum number of characters.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * @n: Maximum number of characters to copy.
 * Return: Pointer to the resulting string.
 */
char *_strncpy(char *dest, char *src, int n)
{
int i;

i=0;
while (i< n && src[i] !='\0')
{
dest[i] = src[i];
i++;
}

while (i < n)
{
dest[i] = '\0';
i++;
}

return (dest);
}

