#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*operation)(int, int);
	char *operator;

	if (argc != 4)
	{
		printf("Error: Usage: %s num1 operator num2\n", argv[0]);
		return (98);
	}

	num1 = atoi(argv[1]);
	operator = argv[2];
	num2 = atoi(argv[3]);

	operation = get_op_func(operator);

	if (operation == NULL)
	{
		return (99);
	}

	result = operation(num1, num2);

	printf("%d\n", result);

	return (0);
}

