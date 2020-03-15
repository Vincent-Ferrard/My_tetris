/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display
*/

#include "main.h"

void display_tetrimino(map_t *map, int line, int column, int i, int j, option_t *option)
{
	if (j >= column && j < map[2].column + column
		&& i >= line && i < map[2].line + line) {
		if (map[2].tab[i - line][j - column] == '*') {
			attron(COLOR_PAIR(option->past + 1));
			printw("%c", map[0].tab[i][j]);
			attroff(COLOR_PAIR(option->past + 1));
		} else
			printw("%c", map[0].tab[i][j]);
	} else
		printw("%c", map[0].tab[i][j]);
}

void display_next(map_t *map, int i, option_t *option)
{
	for (i = 0; i < map->column + 4; i++)
		printw("-");
	printw("\n|");
	for (i = 0; i < map->column + 2; i++)
		printw(" ");
	printw("|\n");
	for (i = 0; map->tab[i]; i++) {
		printw("| ");
		attron(COLOR_PAIR(option->next + 1));
		printw("%s", map->tab[i]);
		attroff(COLOR_PAIR(option->next + 1));
		printw(" |\n");
	}
	printw("|");
	for (i = 0; i < map->column + 2; i++)
		printw(" ");
	printw("|\n");
	for (i = 0; i < map->column + 4; i++)
		printw("-");
}

void display(map_t *map, int line, int column, option_t *option)
{
	int i;
	int j;

	for (i = 0; map[0].tab[i]; i++) {
		printw("|");
		for (j = 0; map[0].tab[i][j]; j++)
			display_tetrimino(map, line, column, i, j, option);
		printw("|\n");
	}
	for (i = 0; i < map[0].column + 2; i++)
		printw("-");
	printw("\n\n");
	display_next(&map[3], 0, option);
	printw("\n\n+----------------------+\n\n");
	printw("      Level      %d\n", option->level);
	printw("      Line       %d\n", option->line);
	printw("      Score      %d\n", option->score);
	printw("\n+----------------------+\n");
}
