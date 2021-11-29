#include "main.h"

/**
 * mem_mgmt - function to free main data struct 
 * @cmd: main data struct
 * Return: 0 if successfully free data, otherwise -1 on error
 */
void mem_mgmt(struct command *_cmd)
{
	/* TODO - REVIEW AND DEFINE ERROR TYPES */
	if (_cmd->cmd != NULL)
		free(_cmd->cmd);
	if (_cmd->path != NULL)
		free(_cmd->path);
	if (_cmd->input != NULL)
		free(_cmd->input);
}

/**
 * check_overflow - checks if newSize is bigger than current MAX
 * adds space if necessary
 * @m_buffer: main buffer string
 * @new_bytes: new data to be stored
 * Return: none - void
 */
void check_overflow(struct command *_cmd, unsigned int new_bytes)
{
	/* TODO */
	(void)new_bytes;
	(void)_cmd;
}

/**
 * init_cmd - initialize main struct
 * @_cmd: main struct
 * Return: none - void
 */
void init_cmd(struct command *_cmd, char **envir)
{
	_cmd->cmd = malloc(sizeof(char *) * MAXCMDSIZE);
	_cmd->path = malloc(sizeof(char *) * MAXCMDSIZE);
	_cmd->env_list = envir;
	_cmd->input = NULL;
	_cmd->full_cmd_path = NULL;
	_cmd->status_code = BASE_STATUS;	
	_cmd->flags = 0;
	_cmd->size = 0;

	if (_cmd->cmd == NULL || _cmd->env_list == NULL || _cmd->path == NULL)
		mem_mgmt(_cmd);
}