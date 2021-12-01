#include "main.h"

/**
 * get_cwd - get current directory
 * Return: string with current directory
 */
char *get_cwd()
{
	char buff[512];
	char *cwd;
	size_t n = 0;
	int i = 0;

	getcwd(buff, 512);
	n = strlen(buff);
	cwd = malloc(sizeof(char) * (n + 1));
	if (cwd == NULL)
		return (NULL);
	while (i < (int)n)
	{
		cwd[i] = buff[i];
		i++;
	}
	return (cwd);
}

/**
 * print_prompt - prints desc + username
 * Return: none - void function
 */
void print_prompt_2()
{
	char *cwd, *prompt, *home;

	/* get current directory */
	cwd = get_cwd();
        if (cwd == NULL)
		return;
	/* replace home dir with ~ */
	home = getenv("HOME");
	cwd = str_replace(cwd, home, "~", 0);
	cwd[strlen(cwd) - 1] = '\0';

	/* concatenate prompt message */
	prompt = _concat(6, GREEN, "[shell-v0.1]", LIGHT_BLUE, cwd, "$ ", BROWN);
	write(STDOUT_FILENO, prompt, strlen(prompt));
	free(cwd);
	free(prompt);
}

/**
 * print_prompt - prints desc + username
 * Return: none - void function
 */
void print_prompt()
{	
	write(STDOUT_FILENO, "\033[0;32mShell-$ \033[0;33m", 23);
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

	_cmd->input = NULL;
	nread = getline(&(_cmd->input), &len, stdin);
	if (nread == EOF)
	{
		_cmd->status_code = EXIT_STATUS;
	}
	_cmd->input[nread - 1] = '\0';
	_cmd->size = nread;
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
