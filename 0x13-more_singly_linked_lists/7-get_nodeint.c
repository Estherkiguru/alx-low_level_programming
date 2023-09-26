#include "lists.h"

/**
 * get_nodeint_at_index - Returns the node at a given index
 *				in a  linked list
 * @head: points to the pointer in the head of the linked list
 * @index:index of the node, starting at 0
 *
 * Return:Pointer to the node at the specified index,
 *		or NULL if not found.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int i = 0;

	while (current != NULL)
	{
		if (i == index)
			return (current);

	current = current->next;
	i++;
	}
return (NULL);
}
