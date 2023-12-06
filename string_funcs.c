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
