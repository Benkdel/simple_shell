#include "../../main.h"

/**
 * str_replace_tests - replaces a string with another one
 * @buffer: buffer with the string
 * @old: str to be replacecd
 * @new: new str
 * @fpos: starting position old str, starting at index 0
 * Return: pointer to char * buffer
 */
char *str_replace_tests(char *buffer, char *old_s, char *new_s, int fpos)
{
	int i, j, k;
	size_t len_old, len_new, len_total;
	char *temp;

	len_old = strlen(old_s);
	len_new = strlen(new_s);
	len_total = strlen(buffer) - len_old + len_new;

	/* assign memory for remaining buffer */
	temp = malloc(sizeof(char) * len_total);
	if (temp == NULL)
		return (NULL);

	for (i = 0, j = 0; buffer[i]; i++)
	{
		if (i < fpos || i > (fpos + len_old - 1))
		{
			temp[j] = buffer[i];
			j++;
		}
		if (i == fpos)
		{
			for (k = 0; new_s[k]; k++)
			{
				temp[j] = new_s[k];
				j++;
			}
			i += len_old - 1;
		}
	}
	return (temp);
}

/**
 * main - testing str_replace method
 * 
 */
int main(void)
{
	char *buffer, *old_s, *new_s;

	buffer = "/home/cbentin/holberton_school/myShell";
	old_s = getenv("HOME");
	new_s = "~/";

	/* result should be of the form: "/home/cbentind/holberton_university/myShell" */

	printf("Old string -> %s\n", buffer);

	buffer = str_replace_tests(buffer, old_s, new_s, 0);

	printf("New string -> %s\n", buffer);

	return (0);
}
