#include "main.h"

/**
 * init_shell - init shell with message
 * Return: none - void function
 */
void init_shell()
{
	char *user_name = getenv("USER");

	clear();
	printf("\n\n******************"
	       "************************");
	printf("\n\t****\033[0;32mShell Project****");
	printf("\n\n\t> \033[1;34mAuthors:");
	printf("\n\t\t- \033[1;37mHumberto Tejada");
	printf("\n\t\t- \033[1;37mCarlos Bentin");
	printf("\n\n\n*******************"
	       "***********************");
	printf("\n\n\n\033[0;32mCURRENT USER: @%s\n", user_name);
	
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

	if (_cmd->cmd == NULL)
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
		}
		else
		{
			wait(&status);
		}
	}
	else
	{
		if (_cmd->status_code == BASE_STATUS)
			_cmd->status_code = SYS_CMD_NOTFOUND;
	}
}
