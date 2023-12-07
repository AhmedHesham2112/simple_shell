#include "shell.h"
/**
 * check_command - checks the entered command and removes \n by \0 in the end.
 * @command: the command to be checked.
 * Return: void.
 */
char *check_command(char *command)
{
	size_t bufsize = sizeof(command);
	ssize_t characters;

	characters = getline(&command, &bufsize, stdin);
	if (characters == -1)
		exit(EXIT_FAILURE);
	else if (characters > 0 && command[characters - 1] == '\n')
		command[characters - 1] = '\0';
	return (command);
}

/**
 * addTextToStart - adds text to the start of a string
 * @original: the original string
 * @textToAdd: the string to be added at the start
 * Return: the full string
 */

char *addTextToStart(const char *original, const char *textToAdd)
{
	size_t originalLength = strlen(original);
	size_t textToAddLength = strlen(textToAdd);
	size_t newLength = originalLength + textToAddLength + 1;
	char *newString = malloc(sizeof(char) * newLength);

	if (newString == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	strcpy(newString, textToAdd);
	strcpy(newString + textToAddLength, original);
	return (newString);
}
