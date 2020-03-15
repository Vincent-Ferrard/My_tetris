/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "main.h"

char **my_strcpy_array(char **map, char **map2)
{
	int i;
	int j;

	for (i = 0; map[i]; i++)
		for (j = 0; map[i][j]; j++)
			map2[i][j] = map[i][j];
	return (map2);
}

char **set_map(char **s, char **map, int line, int column)
{
	int i;
	int j;

	for (i = 0; s[i]; i++)
		for (j = 0; s[i][j]; j++) {
			if (map[i + line][j + column] == ' ')
				map[i + line][j + column] = s[i][j];
		}
	return (map);
}

char **remove_line(char **map, int i, option_t *option)
{
	int j;
	int line = i;

	for (i = line; i > 0; i--)
		for (j = 0; map[i][j]; j++)
			map[i][j] = map[i - 1][j];
	for (j = 0; map[0][j]; j++)
		map[0][j] = ' ';
	option->line += 1;
	option->score += 200;
	if (option->line >= 10) {
		option->line -= 10;
		option->level += 1;
	}
	return (map);
}

void game(map_t *map, int *column, int *line, option_t *option, char **tab)
{
	int i;

	if (check_end(map, map[2].line + *line, *column) == 0) {
		map[0].tab = check_line(map[0].tab, option);
		map[1].tab = my_strcpy_array(map[0].tab, map[1].tab);
		check_exit(map[1].tab);
		for (i = 0; tab[i]; i++);
		option->past = option->next;
		option->next = rand() % i;
		map[2].tab = create_tetrimino(&map[2], tab, option->past);
		map[3].tab = create_tetrimino(&map[3], tab, option->next);
		*line = 0;
		*column = rand() % (9 - map[2].column);
	} else {
		map[0].tab = my_strcpy_array(map[1].tab, map[0].tab);
		*line += 1;
		option->score += 1;
	}
}

void tetris_play(char **tab)
{
	WINDOW *win = initscr();
	option_t option = init_option(win);
	map_t *map = init_map(tab, &option);
	keys_t key = init_all_key();
	int line = 0;
	int column = init_all(win, map[2].column);

	while (1) {
		clear();
		map[0].tab = set_map(map[2].tab, map[0].tab, line, column);
		display(map, line, column, &option);
		nodelay(win, 1);
		timeout(500);
		game(map, &column, &line, &option, tab);
		column = event_key(&key, map, line, column);
	}
}
