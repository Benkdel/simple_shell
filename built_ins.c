#include "main.h"

/**
 * exit_shell - exit shell, sets flag value to -1
 * @_cmd: main data struct
 * Return: none - void function
 */
void exit_shell(struct command *_cmd)
{
	_cmd->status_code = EXIT_STATUS;
	if (_cmd->cmd[1] != NULL)
		_cmd->exit_code = atoi(_cmd->cmd[1]);
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
	struct stat _stat;
	int free_mem = 0;

	old_dir = _getenv("OLDPWD");
	curr_dir = _getenv("PWD");

	if (_cmd->cmd[1] == NULL)
	{
		new_dir = _getenv("HOME");
	}
	else if (strncmp(_cmd->cmd[1], "-", 1) == 0)
	{
		new_dir = old_dir;
		printf("%s\n", new_dir);
	}
	else
	{
		new_dir = get_dir_pathname(_cmd->cmd[1], curr_dir);
		free_mem = 1;
	}

	if (stat(new_dir, &_stat) == 0 && S_ISDIR(_stat.st_mode))
	{
		_setenv("OLDPWD", curr_dir, 1);
		chdir(new_dir);
		_setenv("PWD", new_dir, 1);
	}
	else
		_cmd->status_code = DIR_NOTFOUND;

	if (free_mem == 1)
		free(new_dir);
}

/**
 * env - print current environment
 * @_cmd: main data struct
 * Return: none - void function
 */
void env(struct command *_cmd)
{
	int i = 0;

	for (i = 0; _cmd->env_list[i] != NULL; i++)
	{
		write(STDOUT_FILENO, _cmd->env_list[i], strlen(_cmd->env_list[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
