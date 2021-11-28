#include "../../main.h"


/**
 * main - parse PATH from getenv example
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **envir)
{
	unsigned int i = 0;
	char *path_str;
	char *parsed[1024];

	path_str = getenv("PATH");

	while ((parsed[i] = strtok(path_str, ":")) != NULL)
	{
		printf("Dir[%u]   -> %s\n", i, parsed[i]);
		path_str = NULL;
		i++;
	}
	return (0);
}