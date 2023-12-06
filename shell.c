#include "shell.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
	char command[120];

	while (true)
	{
		if (isatty(STDIN_FILENO) != 0)
			show_prompt();
		execution(check_command(command));
	}
	free(command);
	return (0);
}
