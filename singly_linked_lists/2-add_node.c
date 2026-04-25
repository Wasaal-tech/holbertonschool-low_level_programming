#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * add_node - adds a new node at the beginning of a list
 * @head: pointer to pointer to head of list
 * @str: string to add
 *
 * Return: address of new element, or NULL if failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int i;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
		i++;
	new->len = i;
	new->next = *head;
	*head = new;
	return (new);
}
