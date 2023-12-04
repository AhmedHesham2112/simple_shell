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
		show_prompt();
		execution(check_command(command));
	}

	return (0);
}
