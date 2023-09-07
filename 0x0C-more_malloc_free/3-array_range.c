#include "main.h"
#include <stdio.h>
#include<stdlib.h>

/**
 * array_range - Creates an array of integers.
 * @min: Minimum value.
 * @max: Maximum value.
 *
 * Return: Pointer to the newly created array.
 *If malloc fails or if min > max,
 *returns NULL.
 */
int *array_range(int min, int max)
{
	int *array;
	int i, size;

	if (min > max)
		return (NULL);
	size = max - min + 1;

	array = malloc(sizeof(int) * size);

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = min++;

	return (array);
}
