#include "main.h"
#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	int bit_position = 0;

	if (n > 1)
	{
		bit_position = 1;
		while ((n >> bit_position) > 1)
			bit_position++;
		while (bit_position > 0)
		{
			putchar((n & (1UL << bit_position)) ? '1' : '0');
			bit_position--;
		}
	}
	putchar((n & 1) ? '1' : '0');
}

