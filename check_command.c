#include "shell.h"
/**
 * check_command - checks the entered command and removes \n by \0 in the end.
 * @command: the command to be checked.
 * Return: void.
 */
char *check_command(char *command)
{
	size_t bufsize = 120;
	ssize_t characters;

	characters = getline(&command, &bufsize, stdin);
	if (characters == -1)
		exit(EXIT_FAILURE);
	else if (characters > 0 && command[characters - 1] == '\n')
		command[characters - 1] = '\0';
	return (command);
}
