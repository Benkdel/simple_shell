#ifndef MYSHELL_H
#define MYSHELL_H

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


/* General Macros */
#define clear(void) write(STDOUT_FILENO, " \033[1;1H\033[2J", 12)
#define MAXCMDSIZE 1024

/* STATUS CODES - TODO */
#define BASE_STATUS 0
#define EXIT_STATUS -1
#define SYS_CMD_FOUND 2
#define SYS_CMD_NOTFOUND -2
#define FORK_FAILED -3
#define NOT_FROM_TERMINAL -4

/* Flags */

/* structures */

/**
 * command - command data structure
 * @cmd: array of string with parsed input > command
 * @env_list: envirorment variables  
 * @size: current size of used buffer
 * @path: parsed path from envi list
 * @flags: keep track of currents flags (pipe, exit, etc)
 */
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

/**
 * struct builtin_cmd - choose functions format
 *
 * @key: key is first token of parsed command
 * @b_function: pointer to builtin function
 *
 */
typedef struct builtin_cmd
{
	char *b_key;
	void (*b_function)(struct command *);
} b_cmd;

/* main file - myshell.c*/
int my_shell();

/* shell_calls.c */
void init_shell();
void sys_cmd_exec(struct command *_cmd);

/* shell_IO.c */
void read_command(struct command *);
void print_prompt();
void show_prev_cmd(struct command *);

/* built_ins.c */
void exit_shell(struct command *);
void ppath(struct command *_cmd);
void clear_screen(struct command *_cmd);

/* get_builtin_cmd.c */
void (*get_builtin_cmd(const char *key))(struct command *);

/* mem_mgmt.c */
void mem_mgmt(struct command *);
void check_overflow(struct command *_cmd, unsigned int new_bytes);
void init_cmd(struct command *_cmd, char **envir);
void free_array(char **array);

/* shell_str_parsing */
void parse_input(struct command *_cmd);
char *_getenv(char *local_cmd);
void parse_path(struct command *_cmd);

/* string_methods.c */
char *str_replace(char *buffer, char *old_s, char *new_s, size_t fpos);
char *_concat(size_t num_of_buffers, const char * const format, ...);

/* get_cmd_path */
int get_cmd_path(struct command *_cmd);

/* handle_flags.c */
int handle_status_codes(struct command *_cmd);

/* signals_handler.c */
void _sigint();


/* ===== COLORS ======== */
#define BLACK "\033[0;31m"
#define DARK_GREY "\033[1;30m"
#define LIGHT_GRAY "\033[0;37m"
#define RED "\033[0;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[0;34m"
#define LIGHT_BLUE "\033[1;34m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36"
#define WHITE "\033[1;37m"

#endif
