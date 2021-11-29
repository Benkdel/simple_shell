#include "main.h"

/**
 * print_prompt - prints desc + username
 * Return: none - void function
 */
void print_prompt()
{
	char *buff, *newBuff;
	size_t len_homeDir = 0, i = 0, tot_len = 0;

	/* get current directory */
	buff = malloc(sizeof(char) * 100);
	if (buff == NULL)
	{
		printf("Error allocating memory in buffer - current directoy\n");
		exit(-1);
	}
	getcwd(buff, 100);

	/* replace home dir with ~ */
	len_homeDir = strlen(getenv("HOME"));
	tot_len = strlen(buff) - len_homeDir + 1;
	
	newBuff = malloc(sizeof(char) * tot_len);
	if (newBuff == NULL)
	{
		printf("Error allocating memory in buffer - replacing with ~\n");
		exit(-1);
	}

	newBuff[0] = '~';
	newBuff[1] = '/';

	while (buff[i])
	{
		if (i > len_homeDir)
		{
			newBuff[i - len_homeDir] = buff[i];
		}
		i++;
	}

	printf("[shell-v0.1]%s$ ", newBuff);

	free(buff);
	free(newBuff);
}

/**
 * read_command - function to take input
 * @_cmd: command structure
 * Return: none - void function
 */
void read_command(struct command *_cmd)
{
	int i = 0;
	size_t len = 0;
	ssize_t nread = 0;
	
	fflush(stdin);
	nread = getline(&_cmd->input, &len, stdin);

	/* replacing new line char with nulll */
	while (_cmd->input[i])
	{
		if (_cmd->input[i] == '\n')
			_cmd->input[i] = ' ';
		i++;
	}
	fflush(stdin);
	_cmd->size += nread;
}

/**
 * show_prev_cmd - show previous executed commands on same line
 * @cmd_hist: array of strings with cmd stored
 * Return: none - void function
 */
void show_prev_cmd(struct command *_cmd)
{
	/* TODO */
	/* read from file .... */
	(void)_cmd;
}
