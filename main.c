#include "main.h"

/**
 * main - Entry Point for myShell
 * Return: 0 (on Success)
 */
int main(int argc, char **argv, char **envir)
{
	cmd _cmd;
	void (*b_cmd)(struct command * _cmd);

	(void)argc;
	(void)argv;
	(void)envir;

	/* Init main struct */
	init_cmd(&_cmd);
	_cmd.env_list = envir;

	/* init shell program - display welcoming mssg and authors */
	init_shell();
	print_prompt();

	/* set PATH into tokens */
	parse_path(&_cmd);

	while (1)
	{

		/* Gets input from user and sets size of chars readed */
		read_command(&_cmd);

		if (_cmd.size > 0)
		{
			/* Store Input in History File */
			
			/* === TODO === */

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

		if (_cmd.flags == SYS_CMD_NOTFOUND)
			printf("Command not found!\n");

		if (_cmd.flags == -1)
		{
			/* mem_mgmt(&_cmd); */
			printf("Good Bye!\n");
			sleep(1);
			clear(void);
			return (0);
		}

		/* Print shell desc + USERNAME */
		print_prompt();
	}

	return (0);
}
