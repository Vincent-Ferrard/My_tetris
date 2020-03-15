/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** event
*/

#include "main.h"

int event_key(keys_t *key, map_t *map, int line, int column)
{
	int ch = getch();

	if (ch == key->k_left)
		if (check_column(map, line, column - 1) != 0)
			column--;
	if (ch == key->k_right)
		if (check_column(map, line, column + map[2].column) != 0)
			column++;
	if (ch == key->k_turn)
		map[2].tab = turn_tetrimino(&map[2]);
	if (ch == key->k_pause) {
		map[0].tab = set_map(map[2].tab, map[0].tab, line, column);
		while (getch() != key->k_pause);
	}
	event_key2(key, ch);
	return (column);
}

void event_key2(keys_t *key, int ch)
{
	if (ch == key->k_quit) {
		refresh();
		endwin();
		exit(0);
	}
}
