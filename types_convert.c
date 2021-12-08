#include "main.h"

/**
 * to_str - convert int to string
 * @n: number to be converted into a string
 * Return: pointer to a new string
 */
char *to_str(int n)
{
	char *str, *p;
	int n2 = n, i = 0;

	while (n2 > 0)
	{
		i++;
		n2 /= 10;
	}
	str = malloc(sizeof(char) * (i + 1));
	str[i] = '\0';

	p = &str[i];
	p--;
	while (n > 0)
	{
		*p = n % 10 + '0';
		n /= 10;
		p--;
	}
	return (str);
}
