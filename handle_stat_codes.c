#include "main.h"

/**
 * handle_status_codes - handle diff outcomes depending on flags
 * @_cmd: main data struct
 * Return: -1 to exit, ow a positive number to continue
 */
int handle_status_codes(struct command *_cmd, char *main_file, char *temp_input)
{
	int status = 0;

	switch (_cmd->status_code)
	{
	case EXIT_STATUS:
		status = EXIT_STATUS;
		break;
	case SYS_CMD_NOTFOUND:
		if (_cmd->input_type == F_TERMINAL)
		{
			printf("%s: No such file or directory\n", main_file);	
		}
		else  /*_cmd->input_type == F_NOT_TERMINAL */
		{
			printf("%s: %d: %s: not found\n", main_file, _cmd->lines_counter, temp_input);
		}		
		_cmd->status_code = BASE_STATUS;
		status = 0;
		break;
	case SYS_CMD_FOUND:
		if (_cmd->input_type == F_NOT_TERMINAL)
		{
			_cmd->status_code = EXIT_STATUS;
		}
		else{
			_cmd->status_code = BASE_STATUS;
		}
		break;
	case FORK_FAILED:
		status = EXIT_STATUS;
		break;
	default:
		break;
	}
	return (status);
}
