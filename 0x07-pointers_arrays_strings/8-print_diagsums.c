#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix
 * @a: Pointer to the square matrix
 * @size: Size of the matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
int sum_diag1 = 0, sum_diag2 = 0;
int i, j;

for (i = 0; i < size; i++)
{
for (j = 0; j < size; j++)
{
if (i == j)
sum_diag1 += *(a + i * size + j);

if (i + j == size - 1)
sum_diag2 += *(a + i * size + j);
}
}

printf("%d, %d\n", sum_diag1, sum_diag2);
}

