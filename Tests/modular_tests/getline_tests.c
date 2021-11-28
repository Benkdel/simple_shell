#include "../../main.h"


/**
 * main - Testing getline + parsing
 * @argc:
 * @argv:
 * @envi: 
 * Return: none - void function
 */
int main(int argc, char **argv, char **envi)
{
	(void)argc;
	(void)argv;
	(void)envi;

	int i = 0;
	ssize_t nread;
	size_t len = 0;
	char *input = NULL;
	char **parsed_cmd;
	char *currToken;

	nread = getline(&input, &len, stdin);
	if (nread == -1)
	{
		printf("Failed to read input from user\n");
		return (-1);
	}
	
	printf("Input after getline: %s\n", input);

	parsed_cmd = malloc(sizeof(char *) * 10);
	if (parsed_cmd == NULL)
	{
		printf("Failed to allocated memory\n");
		return (-1);
	}

	do
	{
		currToken = strtok(input, " ");
		parsed_cmd[i] = currToken;
		printf("Current token[%d] -> %s\n", i, parsed_cmd[i]);
		input = NULL;
		i++;
	} while (currToken != NULL);
	
	printf("Input after parsing: %s\n", input);

	i = 0;
	printf("Parsed Command:\n");
	while (parsed_cmd[i])
	{
		printf("\tToken[%d] -> %s\n", i, parsed_cmd[i]);
		i++;
	}

	
	if (parsed_cmd != NULL)
	{
		free(parsed_cmd);
		free(currToken);
	}

	return (0);
}