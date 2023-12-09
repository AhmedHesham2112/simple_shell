#include "shell.h"

/**
 * _print - prints commands into the terminal.
 * @command: the command to be printed.
 * Return: void.
 */

void _print(const char *command)
{
	write(STDOUT_FILENO, command, _strlen(command));
}
