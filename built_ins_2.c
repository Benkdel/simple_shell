#include "main.h"

/**
 * b_setenv - initialize a new environment variable, or modify an existing one
 * @_cmd: main data struct
 * Return: none - void function
 */
void b_setenv(struct command *_cmd)
{
	char *var = NULL, *value = NULL;
	int owrite = 0;

	if (_cmd->cmd[1] != NULL)
		var = _cmd->cmd[1];
	if (_cmd->cmd[2] != NULL)
		value = _cmd->cmd[2];
	if (_cmd->cmd[3] != NULL)
		var = atoi(_cmd->cmd[3]);

	_setenv(var, value, owrite);
}

/**
 * b_unsetenv - removes an environment variable
 * @_cmd: main data struct
 * Return: none - void function
 */
void b_unsetenv(struct command *_cmd)
{
	char *var = NULL;

	if (_cmd->cmd[1] != NULL)
		var = _cmd->cmd[1];

	_unsetenv(var);
}
