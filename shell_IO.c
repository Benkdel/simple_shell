#include "main.h"

/**
 * print_prompt - prints desc + username
 * Return: none - void function
 */
void print_prompt(void)
{
	print_simple_prompt();
	/* print_fancy_prompt(); */
}

/**
 * print_fancy_prompt - prints desc + username
 * Return: none - void function
 */
void print_fancy_prompt(void)
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
 * print_simple_prompt - prints desc + username
 * Return: none - void function
 */
void print_simple_prompt(void)
{
	/* write simple prompt message */
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}

/**
 * _getline - custome getline function
 * @buff: buffer to read input into
 * @size: size of bytes to read
 * @file: source of input
 * Return: bytes read if succeded, -1 if error
 */
int _getline(char **buff, size_t *size, FILE *file)
{
	char l[1024];
	int n = 0, rd, fd, i = 0;

	if (file == stdin)
		fd = 0;
	else if (file == stdout)
		fd = 1;
	else if (file == stderr)
		fd = 2;
	else
		perror("NO FILE STREAM DETECTED");

	*size = 1024;
	rd = read(fd, l, *size);
	if (rd == -1)
		return (-1);

	while (l[n] != '\0')
	{
		n++;
	}

	while (i < n - 1)
	{
		buff[0][i] = l[i];
		i++;
	}
	return (n - 1);
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

	_cmd->lines_counter++;
	_cmd->input = NULL;
	nread = getline(&(_cmd->input), &len, stdin);
	if (nread == EOF)
	{
		_cmd->status_code = EXIT_STATUS;
		return;
	}
	_cmd->size = nread;
}
