#include "main.h"

/**
 * get_cmd_path - gets path of command in envi
 * @_cmd: main data struct
 * Return: 2 if succeded, -2 if failed
 */
int get_cmd_path(struct command *_cmd)
{
	struct stat _stat;
	int f_stat, i = 0;
	char *conc_path;
	char **path = _cmd->path;
	size_t len_cmd, len_tot;

	len_cmd = strlen(_cmd->cmd[0]);

	/* check if file exists using only command */
	f_stat = stat(_cmd->cmd[0], &_stat);
	if (f_stat == 0)
	{
		_cmd->full_cmd_path = strdup(_cmd->cmd[0]);
		return (SYS_CMD_FOUND);
	}

	/* check if file exists pre appending path */
	while (path[i])
	{
		len_tot = strlen(path[i]) + len_cmd + 2;
		conc_path = malloc(sizeof(char) * len_tot);
		if (conc_path == NULL)
			return (SYS_CMD_NOTFOUND);

		conc_path = _concat(3, path[i], "/", _cmd->cmd[0]);

		f_stat = stat(conc_path, &_stat);
		if (f_stat == 0)
		{
			_cmd->full_cmd_path = strdup(conc_path);
			free(conc_path);
			return (SYS_CMD_FOUND);
		}
		free(conc_path);
		i++;
	}
	return (SYS_CMD_NOTFOUND);
}