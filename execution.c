#include "shell.h"

/**
 * execution - excutes commands into that was entered.
 * @command: the command to be executed.
 * Return: void.
 */

void execution(const char *command)
{
	pid_t child_pid;
	char *args[100];
	int arg_count = 0, status = 0;
	char *token = strtok((char *)command, " ");

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;
	if (args[0] == NULL)
		return;
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
			wait(&status);
	}
	else
		execution2(args);
}

/**
 * execution2 - executes with handling the PATH
 * @args: the args passed to be executed
 * Return: void
 */

void execution2(char **args)
{
	char *path = getenv("PATH"), *path_dup = _strdup(path), *paths[100];
	int arg_count = 0, i = 0, status = 0, child_pid;
	char *token = strtok((char *)path_dup, ":"), path_arg[100];

	if (path_dup == NULL)
		exit(EXIT_FAILURE);
	while (token != NULL)
	{
		paths[arg_count++] = token;
		token = strtok(NULL, ":");
	}
	paths[arg_count] = NULL;
	for (i = 0; paths[i] != NULL; i++)
	{
		_strcpy(path_arg, paths[i]);
		_strcat(path_arg, "/");
		_strcat(path_arg, args[0]);
		if (access(path_arg, F_OK) == 0)
			break;
	}
	free(path_dup);
	if (access(path_arg, F_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			_print("Error forking process.\n");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			execve(path_arg, args, NULL);
			_print("./shell: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
	}
	else
		_print("./shell: Command not found\n");
}
