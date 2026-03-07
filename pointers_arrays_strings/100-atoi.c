#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
	int i;
	int neg_count;
	unsigned int num;

	i = 0;
	neg_count = 0;
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			neg_count++;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			if (neg_count % 2 != 0)
				return (-(int)num);
			return ((int)num);
		}
		i++;
	}
	return (0);
}
