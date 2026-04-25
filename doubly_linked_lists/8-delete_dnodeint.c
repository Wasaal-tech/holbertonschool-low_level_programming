#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes node at given index
 * @head: pointer to pointer to head of list
 * @index: index of node to delete
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i;

	if (*head == NULL)
		return (-1);
	tmp = *head;
	i = 0;
	while (tmp != NULL && i < index)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL)
		return (-1);
	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;
	else
		*head = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	free(tmp);
	return (1);
}
