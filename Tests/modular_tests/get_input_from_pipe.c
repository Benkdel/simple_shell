#include "../../main.h"


/**
 * main - testing dif kinds of input
 * 
 */
int main(int argc, char **argv, char **envi)
{
	size_t len = 0;
	ssize_t count = 0;
	char *buffer;

	(void)argc;
	(void)argv;
	(void)envi;

	getline(&buffer, &len, stdin);
	count = write(1, buffer, strlen(buffer));

	return (0);
}