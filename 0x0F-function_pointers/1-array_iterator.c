#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - Executes a function on each element of an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @action: A function pointer specifying the action to perform.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array != NULL && action != NULL)
	{
	size_t i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
}

