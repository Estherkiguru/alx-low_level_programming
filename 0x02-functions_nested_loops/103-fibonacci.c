#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
unsigned long int fib1 = 1, fib2 = 2, sum = 0, next;

while (fib1 <= 4000000)
{
if (fib1 % 2 == 0)
sum += fib1;
next = fib1 + fib2;
fib1 = fib2;
fib2 = next;
}

printf("%lu\n", sum);

return (0);
}

