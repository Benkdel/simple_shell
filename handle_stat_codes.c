#include "main.h"

/**
 * handle_status_codes - handle diff outcomes depending on flags
 * @_cmd: main data struct
 * Return: -1 to exit, ow a positive number to continue
 */
int handle_status_codes(struct command *_cmd)
{
	int status = 0;

	switch (_cmd->status_code)
	{
	case EXIT_STATUS:
		mem_mgmt(_cmd);
		write(STDOUT_FILENO, "Good Bye!\n", 11);
		fflush(stdin);
		sleep(1);
		clear(void);
		status = EXIT_STATUS;
		break;
	case SYS_CMD_NOTFOUND:
		write(STDOUT_FILENO, "Command not found!\n", 20);
		_cmd->status_code = BASE_STATUS;
		status = 0;
		break;
	case NOT_FROM_TERMINAL:
		mem_mgmt(_cmd);
		status = EXIT_STATUS;
		break;
	case FORK_FAILED:
		mem_mgmt(_cmd);
		status = EXIT_STATUS;
		break;
	default:
		break;
	}
	return (status);
}
