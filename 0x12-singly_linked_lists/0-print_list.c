#include "lists.h"
#include <stdio.h>

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL || *(h->str) == '\0')
			{
			printf("[0] (nil)\n");
		} else
			{
			printf("[%u] %s\n", h->len, h->str);
		}
	h = h->next;
	count++;
	}

	return (count);
}

