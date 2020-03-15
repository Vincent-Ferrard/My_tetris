/*
** EPITECH PROJECT, 2018
** check.c
** File description:
** check
*/

#include "main.h"

int check_end2(char map, char map2, char map3)
{
	int check = 1;

	if (map == '*' && map2 == '*') {
		if (map3 == '*')
			return (-1);
		check = 0;
	} else if (map == ' ')
		check = 1;
	return (check);
}

int check_end(map_t *map, int line, int column)
{
	int check = 1;
	int k;
	int h = 0;

	if (line >= map[1].line)
		return (0);
	for (int i = column; i < column + map[2].column; i++) {
		k = map[2].line;
		for (int j = line; j > line - map[2].line; j--) {
			if ((check = check_end2(
				map[0].tab[j - 1][i],
				map[1].tab[j][i], map[2].tab[k - 1][h])) == -1)
				return (0);
			k--;
		}
		if (check == 0)
			return (0);
		h++;
	}
	return (1);
}

void check_exit(char **map)
{
	int i;

	for (i = 0; map[0][i]; i++)
		if (map[0][i] == '*') {
			refresh();
			endwin();
			exit(0);
		}
}

int check_column(map_t *map, int line, int column)
{
	int i;

	if (column < 0 || column >= map[1].column)
		return (0);
	for (i = line; i < line + map[2].line; i++)
		if (map[0].tab[i][column + 1] == '*'
			&& map[1].tab[i + 1][column] == '*' && i < 19)
			return (0);
	return (1);
}

char **check_line(char **map, option_t *option)
{
	int i;
	int j;

	for (i = 0; map[i]; i++) {
		for (j = 0; map[i][j] == '*'; j++);
		if (map[i][j] == '\0')
			map = remove_line(map, i, option);
	}
	return (map);
}
