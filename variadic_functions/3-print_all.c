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
	int i;
	int sep;
	char *str;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		if (sep)
			printf(", ");
		if (format[i] == 'c')
		{
			printf("%c", va_arg(args, int));
			sep = 1;
		}
		if (format[i] == 'i')
		{
			printf("%d", va_arg(args, int));
			sep = 1;
		}
		if (format[i] == 'f')
		{
			printf("%f", va_arg(args, double));
			sep = 1;
		}
		if (format[i] == 's')
		{
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s", str);
			sep = 1;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
