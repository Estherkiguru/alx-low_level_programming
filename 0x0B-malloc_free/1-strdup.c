#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: The string to duplicate.
 *
 * Return: On success, returns a pointer to the duplicated string.
 * If str is NULL or insufficient memory was available, returns NULL.
 */
char *_strdup(char *str)
{
char *duplicate;
int len = 0;
int i;

if (str == NULL)
return (NULL);

while (str[len])
len++;

duplicate = malloc(sizeof(char) * (len + 1));

if (duplicate == NULL)
return (NULL);

for (i = 0; i < len; i++)
{
duplicate[i] = str[i];
}

duplicate[len] = '\0';

return (duplicate);
}

