#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

void show_prompt(void);
void _print(const char *command);
char *check_command(char *command);
void execution(const char *command);

/* these are helpful functions to the main functions*/

char *addTextToStart(const char *original, const char *textToAdd);
int find_command_path(const char *command, char *command_path);
#endif
