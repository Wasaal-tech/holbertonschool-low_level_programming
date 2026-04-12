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
	double f;
	int n;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		c = format[i];
		str = NULL;
		if (c == 'c')
		{
			n = va_arg(args, int);
			if (sep)
				printf(", ");
			printf("%c", n);
			sep = 1;
		}
		if (c == 'i')
		{
			n = va_arg(args, int);
			if (sep)
				printf(", ");
			printf("%d", n);
			sep = 1;
		}
		if (c == 'f')
		{
			f = va_arg(args, double);
			if (sep)
				printf(", ");
			printf("%f", f);
			sep = 1;
		}
		if (c == 's')
		{
			str = va_arg(args, char *);
			if (sep)
				printf(", ");
			printf("%s", str ? str : "(nil)");
			sep = 1;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
