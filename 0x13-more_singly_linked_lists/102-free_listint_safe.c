#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Pointer to the pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *current = *h, *temp = NULL;
    size_t count = 0;

    if (*h == NULL)
        return (count);

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        count++;
        free(temp);

        if (temp == *h)
        {
            *h = NULL;
            break;
        }
    }

    return (count);
}

