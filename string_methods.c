#include "main.h"

/**
 * _concat - concatenates two or more strings
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
	memset(buffer, 0, num_of_buffers);

	buffer[0] = strdup(format);
	total_len = strlen(buffer[0]);

	for (i = 1; i < (int)num_of_buffers; i++)
	{
		buffer[i] = va_arg(args, char *);
		total_len += strlen(buffer[i]);
	}

	concat_buffer = malloc(sizeof(char) * (total_len + 1));
	if (concat_buffer == NULL)
		return (NULL);
	memset(concat_buffer, 0, total_len + 1);

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
 * @old: str to be replacecd
 * @new: new str
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
	len_total = strlen(buffer) - len_old + len_new;

	/* assign memory for remaining buffer */
	temp = malloc(sizeof(char) * len_total);
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
	return (temp);
}