#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @str: The input string to encode.
 *
 * Return: Pointer to the modified string.
 */
char *leet(char *str)
{
int i, j;
char leet_letters[] = "aeotlAEOTL";
char leet_numbers[] = "4307143071";

for (i = 0; str[i] != '\0'; i++)
{
for (j = 0; leet_letters[j] != '\0'; j++)
{
if (str[i] == leet_letters[j])
{
str[i] = leet_numbers[j];
break;
}
}
}

return (str);
}

