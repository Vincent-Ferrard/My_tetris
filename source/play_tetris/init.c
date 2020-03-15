/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** init
*/

#include "main.h"

char **create_map(int column, int line, char sign)
{
	int i;
	int j;
	char **map = malloc(sizeof(char *) * (line + 1));

	for (i = 0; i < line; i++)
		map[i] = malloc(sizeof(char) * (column + 1));
	for (i = 0; i < line; i++) {
		for (j = 0; j < column; j++)
			map[i][j] = sign;
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

map_t *init_map(char **tab, option_t *option)
{
	map_t *map = malloc(sizeof(map_t) * 4);
	int i;

	srand(time(NULL));
	map[0].line = option->map_y;
	map[0].column = option->map_x;
	map[0].tab = create_map(map[0].column, map[0].line, ' ');
	map[1].line = option->map_y;
	map[1].column = option->map_x;
	map[1].tab = create_map(map[1].column, map[1].line, ' ');
	check_tetrimino(tab);
	for (i = 0; tab[i]; i++);
	option->past = rand() % i;
	option->next = rand() % i;
	map[2].tab = create_tetrimino(&map[2], tab, option->past);
	map[3].tab = create_tetrimino(&map[3], tab, option->next);
	return (map);
}

int init_all(WINDOW *win, int column_tetrimino)
{
	int column = rand() % (9 - column_tetrimino - 1);

	attron(A_NORMAL);
	keypad(win, TRUE);
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	return (column);
}
