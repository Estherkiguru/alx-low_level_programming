#include "main.h"
/**
 * print_times_table - Prints the n times table.
 * @n: The number of times to print the table (0 <= n <= 15).
 */
void print_times_table(int n)
{
int row, column, product;
if (n < 0 || n > 15)
return;
for (row = 0; row <= n; row++)
{
_putchar('0'); /* Print the first column */
for (column = 1; column <= n; column++)
{
product = row * column;
_putchar(',');
_putchar(' ');
if (product < 10)
{
_putchar(' ');
_putchar(' ');
}
else if (product < 100)
{
_putchar(' ');
}
if (product >= 100)
{
_putchar((product / 100) + '0');
_putchar(((product / 10) % 10) + '0');
_putchar((product % 10) + '0');
}
else if (product >= 10)
{
_putchar((product / 10) + '0');
_putchar((product % 10) + '0');
}
else
{
_putchar(product + '0');
}
}
_putchar('\n');
}
}
