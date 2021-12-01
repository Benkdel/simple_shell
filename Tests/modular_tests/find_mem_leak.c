#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>


typedef struct command
{
	char **cmd;
	char **env_list;
	char **path;
	char *input;
	char *full_cmd_path;
	int status_code;
	int flags;
	ssize_t size;
} cmd;

 /** read_command - function to take input
 * @_cmd: command structure
 * Return: none - void function
 */
void read_command(struct command *_cmd)
{
	size_t len = 0;
	ssize_t nread = 0;

	_cmd->input = NULL;
	nread = getline(&(_cmd->input), &len, stdin);

	if (nread == EOF)
	{
		_cmd->status_code = -1;
	}
	_cmd->size = nread;
}

/**
 * get_occurrences - counts number of occurrences of a char
 * @c: char to look for
 * @str: string to look in
 * Return: size_t times
 */
size_t get_occurrences(char c, char *str)
{
	size_t len = 1, i;

	for (i = 1; str[i]; i++)
	{
		if (str[i] == c)
			len++;
	}
	return (len);
}

/**
 * parse_input - parse input from user and store it in buffer
 * @str: string to parse
 * @del: delimiter
 * Return: double pointer - void function
 */
char **parse_input(char *str, char *del)
{
	char *str1, *token;
        char **parsed;
	size_t size, j;

	size = get_occurrences(' ', str) + 1;
	parsed = (char **)malloc(sizeof(char *) * size);
	for(j = 0; j < size; j++)
		parsed[j] = NULL;
	
	if (parsed == NULL)
		return (NULL);

        for (j = 0, str1 = str; ; j++, str1 = NULL)
        {
                token = strtok(str1, del);
                if (token == NULL)
                        break;
                parsed[j] = token;
        }

	return (parsed);
}


/**
 * mem_leak - finding memory leaks 
 * 
 */
int main(void)
{
	cmd _cmd;
	int i;
	char *temp;

	while (1)
	{
		read_command(&_cmd);
		temp = malloc(sizeof(char) * (_cmd.size + 1));
		memset(temp, 0, _cmd.size + 1);

		temp = strncpy(temp, _cmd.input, _cmd.size);
		temp[strlen(temp) - 1] = '\0';
		_cmd.cmd = parse_input(temp, " \n");
		
		if (strncmp(_cmd.cmd[0], "exit", 4) == 0)
		{
			free(_cmd.cmd);
			free(_cmd.input);
			return (0);
		}
		printf("%s", _cmd.input);

		printf("Parsed command: \n");
		for (i = 0; _cmd.cmd[i]; i++)
			printf("%s ", _cmd.cmd[i]);
		putchar(10);

		free(temp);
		free(_cmd.input);
		free(_cmd.cmd);
	}
	return (0);
}