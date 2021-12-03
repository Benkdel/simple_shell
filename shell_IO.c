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
void print_prompt()
{
	char *pwd, *home;
	ssize_t home_found = 0;

	/* get current directory */
	pwd = _getenv("PWD");

	/* replace home dir with ~ */
	home = getenv("HOME");
	if (find_subnstr(pwd, home, strlen(home)) != -1)
	{
		pwd = str_replace(pwd, home, "~", 0);
		home_found = 1;
	}
	pwd[strlen(pwd) - 1] = '\0';

	/* concatenate prompt message */
	write(STDOUT_FILENO, GREEN, strlen(BLUE));
	write(STDOUT_FILENO, "#cisfun$ ", 10);
	write(STDOUT_FILENO, BROWN, strlen(BLUE));
	write(STDOUT_FILENO, pwd, strlen(pwd));
	write(STDOUT_FILENO, WHITE, strlen(WHITE));
	write(STDOUT_FILENO, "$ ", 3);

	if (home_found == 1)
		free(pwd);
}

/**
 * print_prompt - prints desc + username
 * Return: none - void function
 */
void print_prompt_2()
{
	write(STDOUT_FILENO, BROWN, strlen(BLUE));
	write(STDOUT_FILENO, "#cisfun$ ", 10);
	write(STDOUT_FILENO, WHITE, strlen(WHITE));
	/* write(STDOUT_FILENO, "\033[00;32m-cisfun$ \033[00;00m", 23);*/
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
