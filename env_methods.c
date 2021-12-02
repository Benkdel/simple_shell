#include "main.h"

/**
 * _setenv - initialize a new environment variable, or modify an existing one
 * @variable: var to initt or mod
 * @value: value to assign
 * @overwrite: false -> 0 || true -> non zero
 * Return: none - void function
 */
void _setenv(const char *variable, const char *value, int overwrite)
{
	if (setenv(variable, value, overwrite) != 0)
	{
		printf("Failed to set or modify env variable - Error Num: %d\n", errno);
	}
}

/**
 * _unsetenv - removes an environment variable
 * @variable: var to initt or mod
 * Return: none - void function
 */
void _unsetenv(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		printf("Failed to delete env variable - Error Num: %d\n", errno);
	}
}

/**
 * _getenv - get env variable from path
 * @local_cmd: local cmd
 * Return: pointer to result if found. Ow, NULL
 */
char *_getenv(char *local_cmd)
{
	return (getenv(local_cmd));
}