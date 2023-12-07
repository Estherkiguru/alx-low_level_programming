#include "lists.h"
#include <stdlib.h>
/**
 * delete_dnodeint_at_index - Deletes the node at a given index
 * @head: Pointer to a pointer to the head of the doubly linked list
 * @index: Index of the node to be deleted (starting from 0)
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current, *temp;
unsigned int count = 0;
if (head == NULL || *head == NULL)
return (-1);
if (index == 0)
{
temp = *head;
*head = (*head)->next;
if (*head != NULL)
(*head)->prev = NULL;
free(temp);
return (1);
}

current = *head;
while (current != NULL)
{
if (count == index)
{
if (current->next != NULL)
current->next->prev = current->prev;
current->prev->next = current->next;
free(current);
return (1);
}
current = current->next;
count++;
}

return (-1);
}
