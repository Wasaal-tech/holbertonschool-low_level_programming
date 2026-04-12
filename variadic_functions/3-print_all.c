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

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		str = NULL;
		if (format[i] == 'c')
			printf("%s%c", sep++ ? ", " : "", va_arg(args, int));
		else if (format[i] == 'i')
			printf("%s%d", sep++ ? ", " : "", va_arg(args, int));
		else if (format[i] == 'f')
			printf("%s%f", sep++ ? ", " : "", va_arg(args, double));
		else if (format[i] == 's')
		{
			str = va_arg(args, char *);
			printf("%s%s", sep++ ? ", " : "", str ? str : "(nil)");
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
