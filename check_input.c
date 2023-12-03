#include "shell.h"

char *check_command(char *command)
{
	size_t bufsize = 0;
	ssize_t characters;

	characters = getline(&command, &bufsize, stdin);

	if (characters == -1)
	{
		_print("Error while reading input.\n");
		exit(EXIT_FAILURE);
	}
	else if (characters > 0 && command[characters - 1] == '\n')
	{
		command[characters - 1] = '\0';
	}
	return (command);
}
