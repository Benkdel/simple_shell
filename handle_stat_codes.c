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
		status = EXIT_STATUS;
		break;
	case SYS_CMD_NOTFOUND:
		write(STDOUT_FILENO, "Command not found!\n", 20);
		_cmd->status_code = BASE_STATUS;
		status = 0;
		break;
	case NOT_FROM_TERMINAL:
		status = EXIT_STATUS;
		break;
	case FORK_FAILED:
		status = EXIT_STATUS;
		break;
	default:
		break;
	}
	return (status);
}
