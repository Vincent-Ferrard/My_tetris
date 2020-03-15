/*
** EPITECH PROJECT, 2018
** test.c
** File description:
** test
*/

#include "main.h"

char **turn_tetrimino(map_t *mapy)
{
	int i = mapy->column;
	int h = 0;
	int k = 0;
	char **map = malloc(sizeof(char *) * (mapy->column + 1));

	mapy->column = mapy->line;
	mapy->line = i;
	for (i = 0; i < mapy->line + 1; i++)
		map[i] = malloc(sizeof(char) * (mapy->column + 1));
	for (int j = 0; mapy->tab[0][j]; j++) {
		for (i = mapy->column - 1; i >= 0; i--) {
			map[h][k] = mapy->tab[i][j];
			k++;
		}
		map[h][k] = '\0';
		k = 0;
		h++;
	}
	map[h] = NULL;
	return (map);
}
