#include "main.h"

/**
 * main - Entry Point for myShell
 * @argc: argument count
 * @argv: string of arguments
 * @envir: string of env variables
 * Return: 0 (on Success)
 */
int main(int argc, char **argv, char **envir)
{
	cmd _cmd;
	void (*b_cmd)(struct command * _cmd);
	int status = 0;

	(void)argc, (void)argv, (void)envir;
	init_cmd(&_cmd, envir);
	if (isatty(fileno(stdin)) == 1)
		init_shell(&_cmd);
	while (1)
	{
		signal(SIGINT, _sigint);
		read_command(&_cmd);
		if (_cmd.input_type == F_TERMINAL)
			print_prompt();
	}
	return (0);
}
