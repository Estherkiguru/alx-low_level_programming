#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
unsigned long int fib1 = 1, fib2 = 2, next;

printf("%lu, %lu", fib1, fib2);

for (int i = 2; i < 98; i++)
{
next = fib1 + fib2;
printf(", %lu", next);
fib1 = fib2;
fib2 = next;
}

printf("\n");

return (0);
}

