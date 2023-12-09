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
void execution2(char **args);
void env_print(void);
void exit_print(void);

extern char **environ;

/* these are helpful functions to the main functions*/

int find_command_path(const char *command, char *command_path);
char *tokenizer(char *s, char *c);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
size_t _strlen(const char *str);
int _strcmp(char *s1, char *s2);

#endif
