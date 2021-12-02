#include "main.h"

/**
 * parse_input - parse input from user and store it in buffer
 * @str: string to parse
 * @del: delimiter
 * Return: double pointer - void function
 */
char **parse_str(char *str, char *del)
{
	char *str1, *token;
        char **parsed;
	size_t size, j;

	size = get_occurrences(del[0], str) + 1;
	parsed = (char **)malloc(sizeof(char *) * size);
	for(j = 0; j < size; j++)
		parsed[j] = NULL;
	
	if (parsed == NULL)
		return (NULL);

        for (j = 0, str1 = str; ; j++, str1 = NULL)
        {
                token = strtok(str1, del);
                if (token == NULL)
                        break;
                parsed[j] = token;
        }

	return (parsed);
}

