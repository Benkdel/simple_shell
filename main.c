#include "main.h"

/**
 * main - Entry Point for myShell
 * Return: 0 (on Success)
 */
int main(int argc, char **argv, char **envir)
{
	cmd _cmd;
	void (*b_cmd)(struct command * _cmd);
	int status = 0;

	(void)argc;
	(void)argv;
	(void)envir;

	/* Init main struct */
	init_cmd(&_cmd, envir);

	if (!isatty(fileno(stdin)))
		_cmd.status_code = NOT_FROM_TERMINAL;

	/* init shell program - display welcoming mssg and authors */
	if (_cmd.status_code == BASE_STATUS)
	{
		init_shell();
		print_prompt();
	}

	/* set PATH into tokens */
	parse_path(&_cmd);

	while (1)
	{

		/* Gets input from user and sets size of chars readed */
		read_command(&_cmd);
		if (_cmd.size > 0)
		{
			/* Store Input in History File */
			/* TODO */

			/* Parse Input into cmd - using space as delimiter */
			parse_input(&_cmd);

			/* get built in function if applicable */
			b_cmd = get_builtin_cmd(_cmd.cmd[0]);
			if (b_cmd != NULL)
			{
				b_cmd(&_cmd);
			}
			else
			{
				/* call sys_call_function */
				sys_cmd_exec(&_cmd);
			}
		}

		status = handle_status_codes(&_cmd);
		if (status == EXIT_STATUS)
			return (0);

		/* Print shell desc + USERNAME */
		print_prompt();
	}
	return (0);
}
