<h1 align="center" >
<br>
    <img src="https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg" height="50%" width="40%">
</h1>

<h2 align="center">
    BASIC SHELL FOR LINUX
</h2>

<p align="center">
    <a href="https://github.com/cristhian1107/printf/commits/main">
        <img src="https://img.shields.io/github/last-commit/cristhian1107/printf.svg?style=flat-square&logo=github&logoColor=white" alt="GitHub last commit">
    </a>
    <a href="https://github.com/cristhian1107/printf/issues">
    <img src="https://img.shields.io/github/issues-raw/cristhian1107/printf.svg?style=flat-square&logo=github&logoColor=white"
         alt="GitHub issues">
    </a>
    <a href="https://github.com/cristhian1107/printf/pulls">
    <img src="https://img.shields.io/github/issues-pr-raw/cristhian1107/printf.svg?style=flat-square&logo=github&logoColor=white"
         alt="GitHub pull requests">
    </a>
</p>

<h4 align="center"> TBU () - lightweigth shell TBU </h4>

<p align="center">
    <a href="#Synopsis">Synopsis</a> •
    <a href="#Description">Description</a> •
    <a href="#Structure">Structure</a> •
    <a href="#Supported Functionality">Supported Functionality</a>
    <a href="#Work in Progress">Work in Progress</a>
</p>

***
# OUR OWN SHELL - Emulating the Linux Shell
In this project we try to emulate some functions of the `Linux Shell` using the `C Language` to create the program and using `System Calls` in our program.

# Synopsis:

#### Main Includes:
> * #include <unistd.h>
> * #include <stdarg.h>

### For Testing Includes:
> * #include <stdio.h>
> * #include <stdlib.h>
> * #include <limits.h>
> * #include <string.h>

# Description
The utility of our Own Shell is to interpret the commands that it will execute, commands read from a command line string, standard input or a specified file. The application must make sure that the commands to be executed are in the PATH or other functions created by us from some original linux functions.

Pathname expansion will not fail due to the size of a file.

# Structure
> 1. Clean screen on init and display shell env
> 2. Command is entered - if length is non null, keep it in history
> 3. Parse string, breaking it up into individual strings
> 4. Check for built-in commands
> 5. Check if Pipes are present, handle pipes
> 6. Exec system commands and lib by forking child and calling execvp

# Examples
### INTERACTIVE MODE
```
When we run Our Shell, the following will appear:
CURRENT USER: @humtej1204
Shell-$

If we write an existing command on the command line, our shell will execute the corresponding program:
Shell-$ ls
AUTHORS    Tests        external            get_cmd_path.c       help_files  main.c  man_1_simple_shell  shell_IO.c     shell_str_parsing.c  string_methods.c
README.md  built_ins.c  get_buildint_cmd.c  handle_stat_codes.c  hsh         main.h  mem_mgmt.c          shell_calls.c  signals_handler.c
Shell-$

If we write a command that does not exist on the command line, our shell will give us an error message:
Shell-$ asd
Command not found!
Shell-$
``` 
### NON INTERACTIVE MODE
```
$ echo "ls" | ./hsh
AUTHORS    Tests        external            get_cmd_path.c       help_files  main.c  man_1_simple_shell  shell_IO.c     shell_str_parsing.c  string_methods.c
README.md  built_ins.c  get_buildint_cmd.c  handle_stat_codes.c  hsh         main.h  mem_mgmt.c          shell_calls.c  signals_handler.c
$
``` 

# EXIT STATUS
The following exit values shall be returned:
#### `0`
> The script to be executed consisted solely of zero or more blank lines or comments, or both.
#### `1-125`
> A non-interactive shell detected a syntax, redirection, or variable assignment error.
#### `127`
> A specified command_file could not be found by a non-interactive shell.

# AUTHORS
### Contact Information
##### Please feel free to contact us regarding any matter (specially about mistakes, recomendations and gramar errors)

<p align="center">
Humberto Tejada - 
<a href="https://github.com/humtej1204">
        <img src="https://img.shields.io/badge/Haru-mainPage-blue">
</a>
</p>

<p align="center">
Carlos Bentin -
<a href="https://github.com/Benkdel">
        <img src="https://img.shields.io/badge/Carlos-mainPage-blue">
</a>
</p>
