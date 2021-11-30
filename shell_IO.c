#include "main.h"

/**
 * print_prompt - prints desc + username
 * Return: none - void function
 */
void print_prompt()
{
	/*char *buff, *prompt, *home;
	size_t tot_len = 0;
	ssize_t count = 0;*/

	/* get current directory */
	/*buff = malloc(sizeof(char) * 100);
	if (buff == NULL)
		exit(EXIT_STATUS);
	buff[strlen(buff) - 1] = '\0';
	getcwd(buff, 100);
	*/
	/* replace home dir with ~ */
	/*home = getenv("HOME");
	buff = str_replace(buff, home, "~", 0);*/

	/* concatenate prompt message */
	/*tot_len = 13 + strlen(buff) + 3;
	prompt = malloc(sizeof(char) * tot_len);
	if (prompt == NULL)
		exit(EXIT_STATUS);
	prompt[strlen(prompt) - 1] = '\0';

	memset(prompt, 0, tot_len - 1);
	prompt = _concat(6, GREEN, "[shell-v0.1]", LIGHT_BLUE, buff, "$ ", BROWN);
	free(buff); */
	/* write prompt to the screen */
	/*count = write(STDOUT_FILENO, prompt, strlen(prompt));
	fflush(stdin);
	if (count == -1)
		exit(EXIT_STATUS);
	free(prompt);*/
	write(STDOUT_FILENO, "$ ", 3);
}

/**
 * read_command - function to take input
 * @_cmd: command structure
 * Return: none - void function
 */
void read_command(struct command *_cmd)
{
	size_t len = 0;
	ssize_t nread;

	nread = getline(&(_cmd->input), &len, stdin);
	if (nread == EOF)
	{
		_cmd->status_code = EXIT_STATUS;
	}
	_cmd->input[nread - 1] = '\0';
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
