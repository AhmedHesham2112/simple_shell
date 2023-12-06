#include "shell.h"

/**
 * execution - excutes commands into that was entered.
 * @command: the command to be executed.
 * Return: void.
 */

void execution(const char *command)
{
	pid_t child_pid;
	char *path = getenv("PATH");
	char *args[100], *paths[100], path_arg[100];
	int arg_count = 0, i = 0, status = 0, flag = 0;
	char *token = strtok((char *)command, " ");

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	token = strtok((char *)path, ":");
	arg_count = 0;
	while (token != NULL)
	{
		paths[arg_count++] = token;
		token = strtok(NULL, ":");
	}
	paths[arg_count] = NULL;
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
		while (paths[i] != NULL && flag == 0)
		{
			printf("hellooooooo%s    %i\n", paths[i], flag);
			_strcpy(path_arg, paths[i]);
			_strcat(path_arg, "/");
			_strcat(path_arg, args[0]);
			printf("hellooooooo%s    %i\n", paths[i], flag);

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
					flag = 1;
					printf("hellooooooo%s    %i\n", paths[i], flag);
					execve(path_arg, args, NULL);
					_print("./shell: No such file or directory\n");
					exit(EXIT_FAILURE);
				}
				else
				{
					wait(&status);
				}
				printf("hellooooooo%s    child%i\n", paths[i], getpid());
			}
			i++;
			printf("hellooooooo%s    %i\n", path_arg, flag);

			if (flag == 1)
			{
				printf("hellooooooo%s    %i\n", path_arg, flag);

				break;
			}
		}
		_print("./shell: Command not found\n");
	}
}
