#include "shell.h"

void _print(const char *command)
{
    write(STDOUT_FILENO, command, strlen(command));
}
