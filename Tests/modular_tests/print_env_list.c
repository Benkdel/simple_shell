#include "../../main.h"


/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **envir)
{
	unsigned int i;

	while (envir[i] != NULL)
	{
		printf("Line[%u]:   - %s\n", i, envir[i]);
		i++;
	}

	return (0);
}