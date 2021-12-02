#include "main.h"

/**
 * exit_shell - exit shell, sets flag value to -1
 * Return: none - void function
 */
void exit_shell(struct command *_cmd)
{
	_cmd->status_code = EXIT_STATUS;
	if (_cmd->cmd[1] != NULL)
		_cmd->exit_code = atoi(_cmd->cmd[1]);
}

/**
 * ppath - print parsed path to console
 * @_cmd: main data struct
 * Return: none - void function
 */
void ppath(struct command *_cmd)
{
	int i = 0;

	while (_cmd->path[i])
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

/**
 * change_dir - changes directory to [path]
 * @_cmd: main data struct
 * Return: none - void function
 */
void change_dir(struct command *_cmd)
{
	char *new_dir, *old_dir, *curr_dir;

	old_dir = _getenv("OLDPWD");
	curr_dir = _getenv("PWD");

	if (_cmd->cmd[1] != NULL)
	{
		new_dir = _getenv("HOME");
	}
	else if (strncmp(_cmd->cmd[1], "-", 1) == 0)
	{
		new_dir = old_dir;
	}
	else
	{
		new_dir = _cmd->cmd[1];
	}

	_setenv("PWD", new_dir, 1);
	_setenv("OLDPWD", curr_dir, 1);

	chdir(new_dir);
}