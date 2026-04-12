#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i;
	int sep;
	char *str;
	char c;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		c = format[i];
		str = NULL;
		if (c == 'c')
			printf("%s%c", sep++ ? ", " : "", va_arg(args, int));
		if (c == 'i')
			printf("%s%d", sep++ ? ", " : "", va_arg(args, int));
		if (c == 'f')
			printf("%s%f", sep++ ? ", " : "", va_arg(args, double));
		if (c == 's')
		{
			str = va_arg(args, char *);
			printf("%s%s", sep++ ? ", " : "", str ? str : "(nil)");
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
