/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils
*/

#include "main.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *s)
{
	for (int i = 0; s[i]; i++)
		my_putchar(s[i]);
}

int my_strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++);
	return (i + 1);
}

char *my_strcpy(char *s)
{
	char *dest = malloc(sizeof(char) * my_strlen(s));
	int i;

	for (i = 0; s[i]; i++)
		dest[i] = s[i];
	dest[i] = '\0';
	return (dest);
}

int my_strcmp(char *s1, char *s2)
{
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);

	if (len1 != len2)
		return (0);
	for (int i = 0; s1[i]; i++)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
