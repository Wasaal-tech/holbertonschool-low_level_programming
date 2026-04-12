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
	char *types = "cifs";
	char c;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		c = format[i];
		str = NULL;
		if (c == 'c' || c == 'i' || c == 'f' || c == 's')
		{
			if (sep)
				printf(", ");
			if (c == 'c')
				printf("%c", va_arg(args, int));
			else if (c == 'i')
				printf("%d", va_arg(args, int));
			else if (c == 'f')
				printf("%f", va_arg(args, double));
			else
			{
				str = va_arg(args, char *);
				printf("%s", str ? str : "(nil)");
			}
			sep = 1;
		}
		i++;
	}
	(void)types;
	va_end(args);
	printf("\n");
}
