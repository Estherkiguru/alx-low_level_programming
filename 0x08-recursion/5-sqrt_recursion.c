#include "main.h"

int find_sqrt(int n, int guess);
/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 * @n: The number for which to find the square root.
 *
 * Return: The natural square root of n, or -1 if no square root exists.
 */
int _sqrt_recursion(int n)
{
return (find_sqrt(n, 1));
}

/**
 * find_sqrt - Recursive helper function to find the square root.
 * @n: The number for which to find the square root.
 * @guess: The current guess for the square root.
 *
 * Return: The natural square root of n, or -1 if no square root exists.
 */
int find_sqrt(int n, int guess)
{
if (guess * guess == n)
{
return (guess);
}
else if (guess * guess > n)
{
return (-1);
}

return (find_sqrt(n, guess + 1));
}

