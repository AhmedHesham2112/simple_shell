#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src
 * @dest: the string.
 * @src: input text.
 * Return: Always 0.
 */

char *_strcpy(char *dest, char *src)
{
	int i, j;

	i = 0;

	while (src[i] != '\0')
	{
		i++;
	}

	for (j = 0; j < i; j++)
	{
		dest[j] = src[j];
	}
	dest[j] = '\0';

	return (dest);
}


/**
 * _strcat - concatenates two strings.
 * @dest: first string.
 * @src: second string.
 * Return: concatenated string.
 */

char *_strcat(char *dest, char *src)
{
	int srclen = 0;
	int destlen = 0;
	int i = 0;

	while (src[srclen] != '\0')
		srclen++;
	while (dest[destlen] != '\0')
		destlen++;
	for (i = destlen; i <= (destlen + srclen); i++)
		dest[i] = src[i - destlen];
	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the string given as a parameter.
 * Return: a pointer to the string, or NULL if it fails.
 */

char *_strdup(char *str)
{
	unsigned int i = 0;
	unsigned int j;
	char *c;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[i] != '\0')
	{
		i++;
	}
	c = malloc(sizeof(char) * (i + 1));
	if (c == NULL)
	{
		return (NULL);
	}
	for (j = 0; j <= i; j++)
	{
		c[j] = str[j];
	}
	return (c);
}
