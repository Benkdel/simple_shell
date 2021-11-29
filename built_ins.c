#include "main.h"

/**
 * print_dir - print current directory
 * Return: none - void function
 */
void print_dir()
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("\nCurrent Dir: %s\n", cwd);
}

/**
 * exit_shell - exit shell, sets flag value to -1
 * Return: none - void function
 */
void exit_shell(struct command *_cmd)
{
	_cmd->status_code = EXIT_STATUS;
}

/**
 * ppath - print parsed path to console
 * @_cmd: main data struct
 * Return: none - void function
 */
void ppath(struct command *_cmd)
{
	int i = 0;

	while(_cmd->path[i])
	{
		printf("PATH [%d] -> %s\n", i, _cmd->path[i]);
		i++;
	}
}

/**
 * clear_screen - clears screens
 * @_cmd: main data struct
 * Return: none - void function
 */
void clear_screen(struct command *_cmd)
{	
	(void)_cmd;
	clear(void);
}