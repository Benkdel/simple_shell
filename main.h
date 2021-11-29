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
#define SUCCESS_CODE 0
#define EXIT_CODE -1
#define SYS_CMD_FOUND 2
#define SYS_CMD_NOTFOUND -2
#define FORK_FAILED -3

/* Flags */
#define PIPE_OP "pipe"

/* CMD - PATH ids within structures */
#define cmd_CMD 0
#define cmd_PATH 1

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

/* shell_str_helpers */
void parse_input(struct command *_cmd);
char *_getenv(char *local_cmd);
void parse_path(struct command *_cmd);
void get_cmd_path(struct command *_cmd);

/* _concat.c */
char *_concat(size_t num_of_buffers, const char * const format, ...);

#endif
