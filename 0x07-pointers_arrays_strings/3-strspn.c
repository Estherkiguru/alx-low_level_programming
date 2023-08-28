#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: Pointer to the string to be searched.
 * @accept: Pointer to the string containing bytes to be searched for.
 *
 * Return: Number of bytes in the initial segment of @s
 *         which consist only of bytes from @accept.
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int found;
int i;

while (*s != '\0')
{
found = 0
for (i = 0; accept[i] != '\0'; i++)
{
if (*s == accept[i])
{
count++;
found = 1;
break;
}
}

if (!found)
{
break;
}

s++;
}

return (count);
}

