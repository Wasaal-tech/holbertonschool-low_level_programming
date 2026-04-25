#include "lists.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer to head of list
 * @idx: index where new node should be added
 * @n: integer to add
 *
 * Return: address of new node, or NULL if failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *tmp;
	unsigned int i;

	if (idx == 0)
		return (add_dnodeint(h, n));
	tmp = *h;
	i = 0;
	while (tmp != NULL && i < idx - 1)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL)
		return (NULL);
	if (tmp->next == NULL)
		return (add_dnodeint_end(h, n));
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = tmp->next;
	new->prev = tmp;
	if (tmp->next != NULL)
		tmp->next->prev = new;
	tmp->next = new;
	return (new);
}
