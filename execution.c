#include "shell.h"

/**
 * execution - excutes commands into that was entered.
 * @command: the command to be executed.
 * Return: void.
 */

void execution(const char *command)
{
	pid_t child_pid;
	char *args[20];
	int arg_count = 0, status = 0;
	char *token = strtok((char *)command, " ");

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	if (access(args[0], F_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			_print("Error forking process.\n");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			execve(args[0], args, NULL);
			_print("./shell: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
	else
	{
		_print("./shell: Command not found\n");
	}
}
