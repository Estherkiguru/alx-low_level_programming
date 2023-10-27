#include "main.h"

/**
 * print_binary - Print the binary representation of a number.
 * @n: The unsigned long int number to print in binary.
 */
void print_binary(unsigned long int n)
{
    int i;
    unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
    int flag = 0;

    if (n == 0)
    {
        putchar('0');
        return;
    }

    for (i = 0; i < sizeof(unsigned long int) * 8; i++)
    {
        if ((n & mask) >> (sizeof(unsigned long int) * 8 - 1))
        {
            flag = 1;
            putchar('1');
        }
        else if (flag)
        {
            putchar('0');
        }

        n <<= 1;
    }
}

