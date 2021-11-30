#include "main.h"

/**
 * _sigint - avoids program termination on CTRL+C
 * Return: none - void function
 */
void _sigint()
{
	write(STDOUT_FILENO, "\n", 2);
	print_prompt();
}
