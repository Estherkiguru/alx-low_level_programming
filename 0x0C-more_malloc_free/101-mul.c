#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_positive_number - Check if a string represents a positive number.
 * @str: The string to check.
 *
 * Return: 1 if str is a positive number, 0 otherwise.
 */
int is_positive_number(char *str)
{
	while (*str)
	{
	if (!isdigit(*str))
		return (0);
	str++;
	}
	return (1);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 if successful, 98 for invalid input, and 1 for other errors.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3)
	{
	printf("Error\n");
	return (98);
	}

	if (!is_positive_number(argv[1]) || !is_positive_number(argv[2]))
	{
	printf("Error\n");
	return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	result = num1 * num2;

	printf("%d\n", result);

	return (0);
}

