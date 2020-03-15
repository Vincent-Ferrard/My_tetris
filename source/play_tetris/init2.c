/*
** EPITECH PROJECT, 2018
** init2.c
** File description:
** init2
*/

#include "main.h"

int get_size(char *line, int i)
{
	return (line[i] - 48);
}

void set_line(char *map, char *s, int column)
{
	int i;

	for (i = 0; s[i] && i <= column; i++)
		map[i] = s[i];
	if (i <= column) {
		for (i = i - 1; i < column; i++)
			map[i] = ' ';
		map[i] = '\0';
	} else
		map[i - 1] = '\0';
}

void check_tetrimino(char **tab)
{
	char *name;
	int j;

	for (int i = 0; tab[i]; i++) {
		name = my_strcat("tetriminos/", tab[i]);
		if (check_all_info(name) == -1) {
			j = check_tetrimino2(tab, i);
			tab[j] = NULL;
		}
	}
}

char **get_parameters_map(map_t *mapy, char *s)
{
	int i;
	char **map;

	mapy->column = get_size(s, 0);
	mapy->line = get_size(s, 2);
	map = malloc(sizeof(char *) * (mapy->line + 1));
	for (i = 0; i < mapy->line; i++)
		map[i] = malloc(sizeof(char) * mapy->column);
	return (map);
}

char **create_tetrimino(map_t *mapy, char **tab, int nb_rand)
{
	int fd;
	int nb = 0;
	char *s;
	char **map;

	s = my_strcat("tetriminos/", tab[nb_rand]);
	fd = open(s, O_RDONLY);
	s = line(fd);
	map = get_parameters_map(mapy, s);
	while (nb < mapy->line) {
		s = line(fd);
		set_line(map[nb], s, mapy->column);
		free(s);
		nb++;
	}
	map[nb] = NULL;
	close(fd);
	return (map);
}
