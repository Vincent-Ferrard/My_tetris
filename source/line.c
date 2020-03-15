/*
** EPITECH PROJECT, 2018
** line.c
** File description:
** line
*/

#include "main.h"

char *line(int fd)
{
	int i = 0;
	char *s = malloc(sizeof(char) * 1);

	if (read(fd, &s[0], 1) == 0)
		return (NULL);
	for (i = 1; s[i - 1] != '\n'; i++) {
		s = realloc(s, i + 1);
		if (read(fd, &s[i], 1) == 0)
			break;
	}
	s = realloc(s, i + 1);
	s[i] = '\0';
	return (s);
}
