#include "../../main.h"

/**
 * main - parse CMD example
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **envir)
{
	unsigned int i = 0;
	size_t size = 0;
	char *str_cmd = NULL;
	char **parsed;

	parsed = malloc(sizeof(char *) * 10);
	getline(&str_cmd, &size, stdin);

	i = 0;
	while ((parsed[i] = strtok(str_cmd, " ")) != NULL)
	{
		printf("Dir[%u]   -> %s\n", i, parsed[i]);
		str_cmd = NULL;
		i++;
	}

	free(parsed);
	return (0);
}