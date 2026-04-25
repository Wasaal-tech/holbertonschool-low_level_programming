#include "lists.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: pointer to pointer to head of list
 * @n: integer to add
 *
 * Return: address of new element, or NULL if failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}
