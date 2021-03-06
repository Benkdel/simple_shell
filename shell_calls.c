#include "main.h"

/**
 * init_shell - init shell with message
 * @_cmd: main data struct
 * Return: none - void function
 */
void init_shell(struct command *_cmd)
{
	/* char *user_name = getenv("USER"); */

	_cmd->input_type = F_TERMINAL;
	/* clear(); */
	/**
	* printf("\n\n******************");
	* printf("************************");
	* printf("\n\t****\033[0;32mShell Project\033[1;37m****");
	* printf("\n\n\t\033[1;34m> Authors:");
	* printf("\n\t\t\033[1;37m- Humberto Tejada");
	* printf("\n\t\t\033[1;37m- Carlos Bentin");
	* printf("\n\n\n\033[1;37m*******************");
	* printf("***********************");
	* printf("\n\n\n\033[0;32mCURRENT USER: \033[1;37m@%s\n", user_name);
	*/
	print_prompt();
}

/**
 * sys_cmd_exec - function to execute system command
 * @_cmd: main data struct
 * Return: none - void function
 */
void sys_cmd_exec(struct command *_cmd)
{
	pid_t child_pid;
	int status = -1;

	if (_cmd->cmd == NULL || _cmd->cmd[0] == NULL)
		return;

	/* find path */
	status = get_cmd_path(_cmd);
	if (status == SYS_CMD_FOUND)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			printf("ERROR::fAILED TO CREATE CHILD PROCESS\n");
			_cmd->status_code = FORK_FAILED;
			return;
		}
		if (child_pid == 0)
		{
			execve(_cmd->full_cmd_path, _cmd->cmd, _cmd->env_list);
			free(_cmd->full_cmd_path);
		}
		else
			wait(&status);
	}
	else
	{
		/* handle file not found - error should be set on 127? */
		if (_cmd->status_code == BASE_STATUS)
			_cmd->status_code = SYS_CMD_NOTFOUND;
	}
}
