#include "shell.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
	char command[120];
	char *new_command;

	while (true)
	{
		if (isatty(STDIN_FILENO) != 0)
			show_prompt();
		new_command = check_command(command);
		execution(new_command);
	}
	free(new_command);
	return (0);
}
