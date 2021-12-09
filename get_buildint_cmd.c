#include "main.h"

/**
 * *get_builtin_cmd - evaluates key to return pointer to function
 * @key: user input format
 * Return: pointer to function format
 */
void (*get_builtin_cmd(const char *key))(struct command *_cmd)
{
	b_cmd options[] = {
	    {"exit", exit_shell},
	    {"env", env},
	    {"clear", clear_screen},
	    {"cd", change_dir},
	    {"setenv", b_setenv},
	    {"unsetenv", b_unsetenv},
	    {NULL, NULL}};
	size_t b_key_len;
	int i = 0;

	if (key == NULL)
		return (NULL);

	while (i < 6)
	{
		b_key_len = strlen(options[i].b_key);
		if (strncmp(key, options[i].b_key, b_key_len) == 0)
			return (options[i].b_function);
		i++;
	}
	return (NULL);
}
