#include "main.h"
/**
 * puts_half - Prints the second half of a string.
 * @str: The string to be printed.
 */
void puts_half(char *str)
{
int length = 0;
int start;

while (str[length] != '\0')
{
length++;
}

start = length / 2;
    
if (length % 2 != 0) /* If the length is odd, adjust start index */
{
start++;
}

while (str[start] != '\0')
{
_putchar(str[start]);
start++;
}

_putchar('\n');
}

