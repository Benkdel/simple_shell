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

#include <errno.h>

/* General Macros */
#define clear(void) write(STDOUT_FILENO, " \033[1;1H\033[2J", 12)
#define MAXCMDSIZE 1024

#define DEBUG_MODE 1

/* STATUS CODES - TODO */
#define BASE_STATUS 0
#define EXIT_STATUS -1
#define SYS_CMD_FOUND 2
#define SYS_CMD_NOTFOUND -2
#define FORK_FAILED -3
#define DIR_NOTFOUND -4

/* INPUT TYPE */
#define F_TERMINAL 0
#define F_NOT_TERMINAL 1

/* structures */

/**
 * struct command - command data structure
 * @env_list: envirorment variables
 * @input: command read by readline - raw
 * @cmd: array of string with parsed input > command
 * @full_cmd_path: path pre appending full name if neccesary
 * @status_code: code used to performe shell operations
 * @exit_code: used to signal exit action
 * @input_type: track if input comes from terminal or other source
 * @lines_counter: to display multiple errors if necessary
 * @flags: keep track of currents flags (pipe, exit, etc)
 * @size: current size of used buffer
 */
typedef struct command
{
	char **cmd;
	char **env_list;
	char *input;
	char *full_cmd_path;
	int status_code;
	int exit_code;
	int input_type;
	int lines_counter;
	int flags;
	ssize_t size;
} cmd;

/**
 * struct builtin_cmd - choose functions format
 *
 * @b_key: key is first token of parsed command
 * @b_function: pointer to builtin function
 *
 */
typedef struct builtin_cmd
{
	char *b_key;
	void (*b_function)(struct command *);
} b_cmd;

/* shell_calls.c */
void init_shell(struct command *_cmd);
void sys_cmd_exec(struct command *_cmd);

/* shell_IO.c */
void read_command(struct command *_cmd);
void print_prompt(void);
void print_simple_prompt(void);
void print_fancy_prompt(void);
int _getline(char **buff, size_t *size, FILE *file);

/* get_builtin_cmd.c */
void (*get_builtin_cmd(const char *key))(struct command *_cmd);

/* built_ins.c */
void exit_shell(struct command *_cmd);
void env(struct command *_cmd);
void clear_screen(struct command *_cmd);
void change_dir(struct command *_cmd);

/* built_ins_2.c */
void b_setenv(struct command *_cmd);
void b_unsetenv(struct command *_cmd);

/* mem_mgmt.c */
void init_cmd(struct command *_cmd, char **envir);

/* shell_str_parsing */
char **parse_str(char *str, char *del);

/* env_methods.c */
void _setenv(const char *variable, const char *value, int overwrite);
void _unsetenv(const char *variable);
char *_getenv(char *local_cmd);

/* get_dir_pathname.c */
char *get_dir_pathname(char *target_dir, char *current_dir);

/* string_methods.c */
char *str_replace(char *buffer, char *old_s, char *new_s, size_t fpos);
char *_concat(size_t num_of_buffers, const char *const format, ...);
size_t get_occurrences(char c, char *str);
ssize_t find_subnstr(const char *str, const char *sub, size_t n);

/* get_cmd_path */
int get_cmd_path(struct command *_cmd);

/* handle_flags.c */
int handle_status_codes(struct command *_cmd, char *main_file, char *input);

/* signals_handler.c */
void shell_signal(int sig);

/* types_convert.c */
char *to_str(int n);

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

/* ===== DEBUG ========= */

#endif
