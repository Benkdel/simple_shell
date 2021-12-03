#include "main.h"

/**
 * init_cmd - initialize main struct
 * @_cmd: main struct
 * @envir: envirorment list
 * Return: none - void
 */
void init_cmd(struct command *_cmd, char **envir)
{
	_cmd->env_list = envir;
	_cmd->input = NULL;
	_cmd->full_cmd_path = NULL;
	_cmd->status_code = BASE_STATUS;
	_cmd->input_type = F_TERMINAL;
	_cmd->lines_counter = 0;
	_cmd->flags = 0;
	_cmd->exit_code = 0;
	_cmd->size = 0;
}
