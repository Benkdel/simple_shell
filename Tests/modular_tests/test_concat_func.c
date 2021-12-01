#include "../../main.h"

/**
 * _concat_2 - concatenates two or more strings
 * @format: variadic function - strings buffers to concatenate 
 * Return: pointer to a new string
 */
char *_concat_2(size_t num_of_buffers, const char *const format, ...)
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

	buffer[0] = (char *)format;
	total_len = strlen(buffer[0]);

	for (i = 1; i < num_of_buffers; i++)
	{
		buffer[i] = va_arg(args, char *);
		total_len += strlen(buffer[i]);
	}

	concat_buffer = malloc(sizeof(char) * (total_len + 1));
	concat_buffer[total_len] = '\0';

	if (concat_buffer == NULL)
	{
		free(buffer);	
		return (NULL);
	}
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
 * main - testing concat function
 * 
 */
int main(void)
{

	char *s1, *s2, *s3;
	char *concat;

	s1 = "Hello";
	s2 = "World";
	s3 = "   testing concat";

	concat = _concat_2(3, s1, s2, s3);

	printf("Result: %s\n", concat);
	free(concat);

	return (0);
}