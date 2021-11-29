#include "main.h"

/**
 * _sigint - avoids program termination on CTRL+C
 * Return: none - void function
 */
void _sigint()
{
	fflush(stdin);
	clear();
	print_prompt();
}
