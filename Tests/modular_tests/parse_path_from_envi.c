#include "../../main.h"


/**
 * main - parse PATH example
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **envir)
{
	unsigned int i = 0;
	char *path_str;
	char *parsed[1024];

	while (envir[i])
	{
		if (strncmp(envir[i], "PATH", 4) == 0)
		{
			path_str = envir[i];
			break;
		}
		i++;
	}

	i = 0;
	while ((parsed[i] = strtok(path_str, ":")) != NULL)
	{
		printf("Dir[%u]   -> %s\n", i, parsed[i]);
		path_str = NULL;
		i++;
	}
	return (0);
}