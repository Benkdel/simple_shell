#include "main.h"

/**
 * _concat - concatenates two or more strings
 * @num_of_buffers: number of repeated args passed
 * @format: variadic function - strings buffers to concatenate
 * Return: pointer to a new string
 */
char *_concat(size_t num_of_buffers, const char *const format, ...)
{
	va_list args;
	ssize_t total_len = 0;
	char **buffer;
	char *concat_buffer;
	int i, j, x;

	va_start(args, format);

	buffer = malloc(sizeof(char *) * num_of_buffers);
	if (buffer == NULL)
		return (NULL);
	for (i = 0; i < (int)num_of_buffers; i++)
		buffer[i] = NULL;

	buffer[0] = (char *)format;
	total_len = strlen(buffer[0]);

	for (i = 1; i < (int)num_of_buffers; i++)
	{
		buffer[i] = va_arg(args, char *);
		total_len += strlen(buffer[i]);
	}

	concat_buffer = malloc(sizeof(char) * (total_len + 1));
	if (concat_buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	concat_buffer[total_len] = '\0';
	for (j = 0, i = 0; total_len > 0; j++)
	{
		for (x = 0; buffer[j][x]; x++, i++)
			concat_buffer[i] = buffer[j][x];
		total_len -= x;
	}
	va_end(args);
	free(buffer);
	return (concat_buffer);
}

/**
 * str_replace - replaces a string with another one
 * @buffer: buffer with the string
 * @old_s: str to be replacecd
 * @new_s: new str
 * @fpos: starting position old str, starting at index 0
 * Return: pointer to char * buffer
 */
char *str_replace(char *buffer, char *old_s, char *new_s, size_t fpos)
{
	size_t i, j, k;
	size_t len_old, len_new, len_total;
	char *temp;

	len_old = strlen(old_s);
	len_new = strlen(new_s);
	len_total = strlen(buffer) - len_old + len_new + 1;

	/* assign memory for remaining buffer */
	temp = malloc(sizeof(char) * len_total);
	memset(temp, 0, len_total);
	if (temp == NULL)
		return (NULL);
	for (i = 0, j = 0; buffer[i]; i++)
	{
		if (i < fpos || i > (fpos + len_old - 1))
		{
			temp[j] = buffer[i];
			j++;
		}
		if (i == fpos)
		{
			for (k = 0; new_s[k]; k++)
			{
				temp[j] = new_s[k];
				j++;
			}
			i += len_old - 1;
		}
	}
	temp[strlen(temp)] = '\0';
	return (temp);
}

/**
 * get_occurrences - counts number of occurrences of a char
 * @c: char to look for
 * @str: string to look in
 * Return: size_t times
 */
size_t get_occurrences(char c, char *str)
{
	size_t len = 1, i;

	for (i = 1; str[i]; i++)
	{
		if (str[i] == c)
			len++;
	}
	return (len);
}

/**
 * find_subnstr - finds first occurrence of a substring in string
 * @str: string to look in to
 * @sub: substring to look for
 * @n: number of chars to check
 * Return: position of char if found, otherwise return -1
 */
ssize_t find_subnstr(const char *str, const char *sub, size_t n)
{
	ssize_t position = -1;
	size_t counter = 0, i, j;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == sub[0])
		{
			position = i;
			for (j = 0; j < n && str[i] == sub[j]; i++, j++)
				counter++;
			if (counter == n)
				return (position);
			i -= counter;
			counter = 0;
			position = -1;
		}
	}
	return (position);
}

/**
 * only_spaces - check if input readed is only white spaces
 * @str: string to check
 * @n: size of input readed
 * Return: 0 if true, 1 if false
 */
int only_spaces(const char *str, ssize_t n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str[i] != ' ')
		{
			return (1);
		}
	}
	return (0);
}