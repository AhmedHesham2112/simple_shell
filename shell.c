#include "shell.h"
/*
 *
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
