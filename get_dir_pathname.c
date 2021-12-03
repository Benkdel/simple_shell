#include "main.h"

/**
 * get_dir_pathname - build full path for directory
 * @
 */
char *get_dir_pathname(char *target_dir, char *current_dir)
{
	ssize_t wld_c;
	char *dir_pathname;

	/* check if "../" are found */
	wld_c = find_subnstr(target_dir, "../", 3);
	if (wld_c != -1)
	{
		/* "../" found - go back dirs as ../ and rebuild path*/
		/* TODO */

	}
	else
	{
		if (find_subnstr(target_dir, "/", 1) == 0)
			dir_pathname = _concat(2, target_dir, "/");
		else
			dir_pathname = _concat(3, current_dir, "/", target_dir);
	}
	return (dir_pathname);
}