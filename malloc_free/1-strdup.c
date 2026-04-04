#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to new string, or NULL
 */
char *_strdup(char *str)
{
	char *dup;
	int i;
	int len;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		dup[i] = str[i];
	return (dup);
}
