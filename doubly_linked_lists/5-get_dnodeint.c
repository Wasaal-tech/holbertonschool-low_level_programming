#include "lists.h"
#include <stddef.h>

/**
 * get_dnodeint_at_index - returns the nth node of a list
 * @head: pointer to head of list
 * @index: index of the node
 *
 * Return: pointer to node, or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	i = 0;
	while (head != NULL)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}
	return (NULL);
}
