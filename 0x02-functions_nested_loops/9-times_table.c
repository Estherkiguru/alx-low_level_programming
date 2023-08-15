#include "main.h"

/**
 * times_table - prints the 9 times table, starting from 0
 */
void times_table(void)
{
    int row, col, result;

    for (row = 0; row <= 9; row++)
    {
        _putchar('0'); // Print the first column

        for (col = 1; col <= 9; col++)
        {
            _putchar(',');
            _putchar(' ');

            result = row * col;

            if (result <= 9)
                _putchar(' '); // Extra space for single-digit numbers

            if (result >= 10)
                _putchar((result / 10) + '0'); // Print the tens digit

            _putchar((result % 10) + '0'); // Print the ones digit
        }

        _putchar('\n');
    }
}

