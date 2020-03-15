/*
** EPITECH PROJECT, 2018
** get_tetriminos2.c
** File description:
** get_tetriminos2
*/

#include "main.h"

int check_nb_point(char *s)
{
	int nb = 0;

	for (int i = 0; s[i]; i++)
		if (s[i] == '.')
			nb++;
	return (nb);
}

int get_all_tetriminos(char *s)
{
	int i;
	int j;
	int count = check_nb_point(s);
	int nb = 0;
	char *s2 = malloc(sizeof(char) * my_strlen(s));

	for (i = 0; nb < count; i++)
		if (s[i] == '.')
			nb++;
	for (j = 0; s[i]; i++) {
		s2[j] = s[i];
		j++;
	}
	s2[j] = '\0';
	if (my_strcmp(s2, "tetrimino") == 1)
		return (1);
	free(s2);
	return (0);
}
