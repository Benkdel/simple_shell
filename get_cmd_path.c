#include "main.h"

/**
 * get_cmd_path - get full path of sys command
 * @_cmd: main data struct
 * Return: 2 if succeded, -2 if failed
 */
int get_cmd_path(struct command *_cmd)
{
	struct stat _stat;
	int f_stat, i = 0;
	char *conc_path;
	char **path = _cmd->path;

	/* check if file exists using only command */
	f_stat = stat(_cmd->cmd[0], &_stat);
	if (f_stat == 0)
	{
		_cmd->full_cmd_path = _concat(2, _cmd->cmd[0], "");
		return (SYS_CMD_FOUND);
	}

	/* check if file exists pre appending path */
	while (path[i])
	{
		conc_path = _concat(3, path[i], "/", _cmd->cmd[0]);
		f_stat = stat(conc_path, &_stat);
		if (f_stat == 0)
		{
			_cmd->full_cmd_path = conc_path;
			return (SYS_CMD_FOUND);
		}
		free(conc_path);
		i++;
	}
	return (SYS_CMD_NOTFOUND);
}
