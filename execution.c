

#include "shell.h"

void execution(const char *command)
{

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{

		/*
		 *Child process
		 */
		char *args[120];
		int arg_count = 0;
		char *token = strtok((char *)command, " ");

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		printf("Hello %s\n", args[0]);
		execve("/bin/sjdvfusdb", args, NULL);
		_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
