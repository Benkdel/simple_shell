#include "../../main.h"

/**
 * find_subnstr_2 - finds first occurrence of a substring in string
 * @str: string to look in to
 * @sub: substring to look for
 * @n: number of chars to check
 * Return: position of char if found, otherwise return -1
 */
ssize_t find_subnstr_2(const char *str, const char *sub, size_t n)
{
	ssize_t position = -1, i, j, counter = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == sub[0])
		{
			position = i;
			for (j = 0; j < n && str[i] == sub[j]; i++, j++)
			{
				counter++;
			}
			if (counter == n)
				return (position);
			else
			{
				i -= counter;
				counter = 0;
				position = -1;
			}
		}
	}
	return (position);
}

/**
 * main - testing find substring method
 * 
 */
int main(void)
{
	const char *str, *sub;
	ssize_t pos = -1;

	str = "/home/cb/nd/cbentind/holberton_school/myShell/Tests";
	sub = "cbentind";

	pos = find_subnstr_2(str, sub, 8);

	printf("Position of string: %d\n", (int)pos);

	return (0);
}