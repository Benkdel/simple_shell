#include "main.h"

/**
 * print_prompt - prints desc + username
 * Return: none - void function
 */
void print_prompt()
{
	char *buff, *newBuff, *prompt;
	size_t len_homeDir = 0, i = 0, j = 0, tot_len = 0;
	ssize_t count = 0;

	/* get current directory */
	buff = malloc(sizeof(char) * 100);
	if (buff == NULL)
	{
		printf("Error allocating memory in buffer - current directoy\n");
		exit(-1);
	}
	getcwd(buff, 100);
	buff[strlen(buff) - 1] = '\0';

	/* replace home dir with ~ */
	len_homeDir = strlen(getenv("HOME"));
	tot_len = strlen(buff) - len_homeDir + 2;

	newBuff = malloc(sizeof(char) * tot_len);
	if (newBuff == NULL)
	{
		printf("Error allocating memory in buffer - replacing with ~\n");
		exit(-1);
	}
	memset(newBuff, 0, tot_len);
	newBuff[0] = '~';
	newBuff[1] = '/';
	j = 2;
	while (buff[i])
	{
		if (i > len_homeDir)
		{
			newBuff[j] = buff[i];
			j++;
		}
		i++;
	}

	tot_len += 14;
	prompt = malloc(sizeof(char) * tot_len);
	if (prompt == NULL)
	{
		printf("Error allocating memory in buffer - current directoy\n");
		exit(EXIT_CODE);
	}
	memset(prompt, 0, tot_len);

	prompt = _concat(3, "[shell-v0.1]", newBuff, "$ ");
	
	count = write(STDOUT_FILENO, prompt, strlen(buff));
	if (count == -1)
	{
		printf("error trying to write prompt\n");
		exit(EXIT_CODE);
	}

	free(buff);
	free(newBuff);
	free(prompt);
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

	_cmd->input = NULL;
	nread = getline(&_cmd->input, &len, stdin);
	if (nread == -1)
	{
		mem_mgmt(_cmd);
		exit_shell(_cmd);
	}

	/* replacing new line char with nulll */
	while (_cmd->input[i])
	{
		if (_cmd->input[i] == '\n')
			_cmd->input[i] = '\0';
		i++;
	}
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
