#include <stdio.h>
#include <math.h>

/**
 * main - Finds and prints the largest prime factor of a number.
 *
 * Return: Always 0.
 */
int main(void)
{
unsigned long n = 612852475143;
unsigned long largest_prime = 2;

while (n > 1)
{
if (n % largest_prime == 0)
n /= largest_prime;
else
largest_prime++;
}

printf("%lu\n", largest_prime);

return (0);
}

