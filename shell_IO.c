#include "main.h"

/**
 * print_prompt - prints desc + username
 * Return: none - void function
 */
void print_prompt()
{
	char *buff, *prompt, *home;
	size_t tot_len = 0;
	ssize_t count = 0;

	/* get current directory */
	buff = malloc(sizeof(char) * 100);
	if (buff == NULL)
		exit(EXIT_STATUS);
	getcwd(buff, 100);
	buff[strlen(buff) - 1] = '\0';

	/* replace home dir with ~ */
	home = getenv("HOME");
	buff = str_replace(buff, home, "~", 0);

	/* concatenate prompt message */
	tot_len = 13 + strlen(buff) + 3;
	prompt = malloc(sizeof(char) * tot_len);
	if (prompt == NULL)
		exit(EXIT_STATUS);
	memset(prompt, 0, tot_len);
	prompt = _concat(3, "[shell-v0.1]", buff, "$ ");

	/* write prompt to the screen */
	count = write(STDOUT_FILENO, prompt, strlen(prompt));
	if (count == -1)
		exit(EXIT_STATUS);

	free(buff);
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

	nread = getline(&(_cmd->input), &len, stdin);
	if (nread == EOF)
	{
		_cmd->status_code = EXIT_STATUS;
		return;
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
