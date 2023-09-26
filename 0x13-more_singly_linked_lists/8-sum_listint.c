#include "lists.h"

/**
 * sum_listint - Calculates the sum of all integers in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The sum of all integers in the linked list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}

