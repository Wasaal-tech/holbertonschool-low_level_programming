#include "lists.h"

/**
 * list_len - returns number of elements in a list
 * @h: pointer to head of list
 *
 * Return: number of nodes
 */
size_t list_len(const list_t *h)
{
	size_t n;

	n = 0;
	while (h != NULL)
	{
		h = h->next;
		n++;
	}
	return (n);
}
