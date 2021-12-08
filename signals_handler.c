#include "main.h"

/**
 * shell_signal - function that controls program interruption
 * @sig: integer number
 */
void shell_signal(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n:) ", 4);
}
