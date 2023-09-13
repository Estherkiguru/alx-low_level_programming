#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @cmp: A function pointer specifying
 * the comparison function.
 *
 * Return: The index of the first element
 * for which cmp returns non-zero.
 *If no element matches or if size
 is less than or equal to 0, return -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
if (array != NULL && cmp != NULL && size > 0)
{
int i;

for (i = 0; i < size; i++)
{
if (cmp(array[i]))
{
return (i);
}
}
}
return (-1);
}

