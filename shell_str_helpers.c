#include "main.h"

/**
 * parse_input - parse input from user and store it in buffer
 * @cmd: main data struct
 * @delimiter: delimiter
 * @dest: parse into CMD or PATH
 * Return: none - void function
 */
void parse_input(struct command *_cmd)
{
	char *_input = strdup(_cmd->input);
	char *currToken;
	int i = 0;

	if (_input == NULL)
	{
		printf("Error allocating memory\n");
		mem_mgmt(_cmd);
	}

	do
	{
		currToken = strtok(_input, " ");
		_cmd->cmd[i] = currToken;
		_input = NULL;
		i++;
	} while (currToken != NULL);
	free(_input);
}

/**
 * _getenv - get env variable from path
 * @local_cmd: local cmd
 * Return: pointer to result if found. Ow, NULL
 */
char *_getenv(char *local_cmd)
{
	return (getenv(local_cmd));
}

/**
 * parse_path - set up path in main data struct
 * @_cmd: main data struct
 */
void parse_path(struct command *_cmd)
{
	int i = 0;
	char *currToken;
	char *path_str = _getenv("PATH");

	do
	{
		currToken = strtok(path_str, ":");
		_cmd->path[i] = currToken;
		path_str = NULL;
		i++;
	} while (currToken != NULL);
}

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