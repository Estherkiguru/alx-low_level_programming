#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * 
 * Return: Pointer to the resulting string.
 */
char *_strcat(char *dest, char *src)
{
int dest_len = 0;
int i = 0;

/* Find the length of the destination string */
while (dest[dest_len] != '\0') {
dest_len++;
}

/* Append characters from src to dest */
while (src[i] != '\0') {
dest[dest_len + i] = src[i];
i++;
}

/* Add null terminator to the concatenated string */
dest[dest_len + i] = '\0';

return (dest);
}

