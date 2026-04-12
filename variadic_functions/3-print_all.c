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
	char *fmt;

	va_start(args, format);
	i = 0;
	sep = 0;
	fmt = (char *)format;
	while (fmt && fmt[i])
	{
		str = NULL;
		if (fmt[i] == 'c')
			printf("%s%c", sep ? ", " : "", va_arg(args, int)), sep = 1;
		if (fmt[i] == 'i')
			printf("%s%d", sep ? ", " : "", va_arg(args, int)), sep = 1;
		if (fmt[i] == 'f')
			printf("%s%f", sep ? ", " : "", va_arg(args, double)), sep = 1;
		if (fmt[i] == 's')
		{
			str = va_arg(args, char *);
			printf("%s%s", sep ? ", " : "", str ? str : "(nil)");
			sep = 1;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
