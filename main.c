#include "main.h"

/**
 * main - Entry Point for myShell
 * @argc: argument count
 * @argv: string of arguments
 * @envir: string of env variables
 * Return: 0 (on Success)
 */
int main(int argc  __attribute__((unused)), char **argv, char **envir)
{
	cmd _cmd;
	void (*b_cmd)(struct command *_cmd);
	int status = 0;

	init_cmd(&_cmd, envir);
	if (isatty(fileno(stdin)) == 1)
		init_shell(&_cmd);
	signal(SIGINT, shell_signal);
	while (1)
	{
		read_command(&_cmd);
		if (_cmd.size > 1)
		{
			_cmd.cmd = parse_str(_cmd.input, " \n");
			b_cmd = get_builtin_cmd(_cmd.cmd[0]);
			if (b_cmd != NULL)
				b_cmd(&_cmd);
			else
			{
				sys_cmd_exec(&_cmd);
				if (_cmd.status_code != SYS_CMD_NOTFOUND)
					free(_cmd.full_cmd_path);
			}
			free(_cmd.cmd);
		}
		status = handle_status_codes(&_cmd, argv[0], _cmd.input);
		if (status == EXIT_STATUS)
		{
			free(_cmd.path);
			exit(_cmd.exit_code);
		}
		if (_cmd.input_type == F_TERMINAL)
			print_prompt();
	}
	return (0);
}
