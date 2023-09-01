#include <stddef.h>
#include "main.h"

/**
 * _strchr - Locates a character in a string.
 * @s: Pointer to the string.
 * @c: The character to locate.
 *
 * Return: Pointer to the first occurrence of @c in @s,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return (s);
}
s++;
}

if (*s == c)
{
return (s);
}

return (NULL);
}

