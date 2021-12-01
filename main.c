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
	char *temp_input;

	(void)argc;
	(void)argv;
	(void)envir;

	/* Init main struct */
	init_cmd(&_cmd, envir);

	if (!isatty(fileno(stdin)))
		_cmd.status_code = NOT_FROM_TERMINAL;

	/* init shell program - display welcoming mssg and authors */
	if (_cmd.status_code == BASE_STATUS)
		init_shell();

	/* set PATH into tokens */
	_cmd.path = parse_str(_getenv("PATH"), ":\n");

	while (1)
	{
		print_prompt();

		signal(SIGINT, _sigint);
		
		/* Gets input from user and sets size of chars readed */
		read_command(&_cmd);
		if (_cmd.size > 1)
		{
			/* Parse Input into cmd - using space as delimiter */
			temp_input = malloc(sizeof(char) * (_cmd.size + 1));
			memset(temp_input, 0, _cmd.size + 1);
			temp_input = strncpy(temp_input, _cmd.input, _cmd.size + 1);
			temp_input[strlen(temp_input)] = '\0';
			_cmd.cmd = parse_str(temp_input, " \n");
			free(_cmd.input);

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
				if (_cmd.status_code != SYS_CMD_NOTFOUND)
					free(_cmd.full_cmd_path);
			}
			free(_cmd.cmd);
			free(temp_input);
		}
		_cmd.size = 0;
		status = handle_status_codes(&_cmd);
		if (status == EXIT_STATUS)
		{
			free(_cmd.path);
			return (0);
		}
	}
	return (0);
}
