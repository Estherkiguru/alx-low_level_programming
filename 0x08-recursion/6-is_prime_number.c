#include "main.h"

int check_prime(int n, int divisor);
/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to be checked.
 *check_prime - Recursive function to check for prime.
 * Return: 1 if prime, 0 otherwise.
 */
int is_prime_number(int n)
{
if (n <= 1)
return (0);
if (n == 2)
return (1);

return (check_prime(n, 2));
}

int check_prime(int n, int divisor)
{
if (divisor * divisor > n)
return (1);
if (n % divisor == 0)
return (0);

return (check_prime(n, divisor + 1));
}

