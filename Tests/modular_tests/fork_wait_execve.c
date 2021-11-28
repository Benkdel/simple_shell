#include "../../main.h"

/**
 * main - fork + wait + execve example
 * Return: Always 0.
 */
int main(int argc, char **argv, char **envir)
{
	pid_t child_pid;
	int status;
	char *input[] = {"/bin/ls", "-l", "../../../myShell/", NULL};
	char *cmd;

	cmd = input[0];
	*input = (*input + 1);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("Executing ls command from child %d\n", (int)child_pid);
		execve(cmd, input, envir);
	}
	else
	{
		wait(&status);
		printf("Successfull execution - child PID: %d\n", (int)child_pid);
	}
	return (0);
}