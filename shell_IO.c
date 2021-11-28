#include "main.h"

/**
 * print_prompt - prints desc + username
 * Return: none - void function
 */
void print_prompt()
{
	printf("[shell-v0.1]%s-$ ", getenv("USER"));
}

/**
 * read_command - function to take input
 * @_cmd: command structure
 * Return: none - void function
 */
void read_command(struct command *_cmd)
{
	size_t len = 0;
	ssize_t nread = getline(&_cmd->input, &len, stdin);
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
