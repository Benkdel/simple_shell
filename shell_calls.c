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
	printf("\n\t****Shell Project****");
	printf("\n\n\t> Authors:");
	printf("\n\t\t- Humberto Tejada");
	printf("\n\t\t- Carlos Bentin");
	printf("\n\n\n*******************"
	       "***********************");
	printf("\n\n\nCURRENT USER: @%s\n", user_name);
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

	child_pid = fork();
	if (child_pid == -1)
	{
		printf("ERROR::fAILED TO CREATE CHILD PROCESS\n");
		status = FORK_FAILED;
		return;
	}
	if (child_pid == 0)
	{
		/* find path */
		get_cmd_path(_cmd);
		execve(_cmd->full_cmd_path, &_cmd->cmd[1], _cmd->env_list);
	}
	else
	{
		wait(&status);
	}
	_cmd->flags = status;
}
