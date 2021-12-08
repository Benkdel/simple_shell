#include "main.h"

/**
 * handle_status_codes - handle diff outcomes depending on flags
 * @_cmd: main data struct
 * @main_file: argv[1]
 * @input: input before parsing it to cmd
 * Return: an integer depending on case
 */
int handle_status_codes(struct command *_cmd, char *main_file, char *input)
{
	int status = 0;
	char *str_err, *lines;

	_cmd->size = 0;
	switch (_cmd->status_code)
	{
	case EXIT_STATUS:
		status = EXIT_STATUS;
		break;
	case SYS_CMD_NOTFOUND:
	case DIR_NOTFOUND:
		if (_cmd->input_type == F_TERMINAL)
			perror(main_file);
		else
		{
			lines = to_str(_cmd->lines_counter);
			str_err = _concat(5, main_file, ": ", lines, ": ", input);
			perror(str_err);
			free(str_err);
			free(lines);
		}
		_cmd->status_code = BASE_STATUS;
		status = 0;
		break;
	case SYS_CMD_FOUND:
		if (_cmd->input_type == F_NOT_TERMINAL)
			_cmd->status_code = EXIT_STATUS;
		else
			_cmd->status_code = BASE_STATUS;
		break;
	case FORK_FAILED:
		status = EXIT_STATUS;
		break;
	default:
		break;
	}
	free(_cmd->input);
	return (status);
}
