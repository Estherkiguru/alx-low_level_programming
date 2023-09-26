#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: Points to a pointer to the head node
 *
 * Return: Head node's data
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int value;

	if (head == NULL || *head == NULL)
		return (0);
	temp = *head;
	*head = (*head)->next;

	value = temp->n;

	free(temp);

	return (value);
}
