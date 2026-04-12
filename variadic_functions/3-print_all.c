#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_char - prints a char
 * @args: va_list
 *
 * Return: void
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an int
 * @args: va_list
 *
 * Return: void
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float
 * @args: va_list
 *
 * Return: void
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: va_list
 *
 * Return: void
 */
void print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	printf("%s", str ? str : "(nil)");
}

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
	int j;
	printer_t types[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{0, NULL}
	};

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		j = 0;
		while (types[j].f && types[j].c != format[i])
			j++;
		if (types[j].f)
		{
			if (sep)
				printf(", ");
			types[j].f(args);
			sep = 1;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
