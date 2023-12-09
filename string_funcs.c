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

/**
 *  * _strlen - Returns the length of a string.
 *   * @str: The string to get the length of.
 *    *
 *     * Return: The length of @str.
 */

size_t _strlen(const char *str)
{
	size_t length = 0;

	while (*str++)
		length++;

	return (length);
}
/**
 *  * _strcmp - compares two strings
 *   * @s1: first string to compare
 *    * @s2: second string to compare
 *     *
 *      * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 *       * more than 0 if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
