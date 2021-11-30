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
		currToken = strtok(_input, " \n");
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
		currToken = strtok(path_str, ":\n");
		_cmd->path[i] = currToken;
		path_str = NULL;
		i++;
	} while (currToken != NULL);
}

