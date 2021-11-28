#include "../../main.h"

/**
 * main - getenv
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s envi var name ... \n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%d -> %s\n", i, getenv(av[i]));
		i++;
	}
	return (0);
}