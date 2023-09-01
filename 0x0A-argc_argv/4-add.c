#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * is_digit - Checks if a string consists of only digits
 * @str: The string to check
 *
 * Return: True if all characters are digits, otherwise False
 */
bool is_digit(char *str)
{
while (*str)
{
if (*str < '0' || *str > '9')
{
return (false);
}
str++;
}
return (true);
}

/**
 * main - Entry point of the program
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments
 *
 * Return: 0 (Success) or 1 (Error)
 */
int main(int argc, char *argv[])
{
int sum = 0;
int i;

for (i = 1; i < argc; i++)
{
if (is_digit(argv[i]))
{
sum += atoi(argv[i]);
}
else
{
printf("Error\n");
return (1);
}
}

printf("%d\n", sum);
return (0);
}

