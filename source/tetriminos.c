/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "main.h"

void display_name(char *name)
{
	int i;
	int count = 0;
	int count2 = 0;
	int nb_point = check_nb_point(name);
	int nb = 0;

	for (i = 0; name[i]; i++)
		if (name[i] == '/')
			count++;
	for (i = 0; nb < nb_point && name[i]; i++) {
		if (name[i] == '.')
			nb++;
		if (nb >= nb_point)
			break;
		if (name[i] == '/')
			count2++;
		else if (count2 >= count)
			my_putchar(name[i]);
	}
	my_putstr(" : ");
}

int check_all_info(char *name)
{
	int fd = open(name, O_RDONLY);
	int i;
	char **tab = my_str_to_word_array(line(fd));
	char *s = line(fd);

	if (tab == NULL)
		return (-1);
	for (i = 0; tab[i]; i++);
	if (i < 3)
		return (-1);
	i = 0;
	while (s) {
		i++;
		free(s);
		s = line(fd);
	}
	if (i != char_to_int(tab[1]))
		return (-1);
	close(fd);
	return (0);
}

void get_all_info(int fd)
{
	char *s = line(fd);
	char **tab;

	tab = my_str_to_word_array(s);
	my_putstr("Size : ");
	my_putstr(tab[0]);
	my_putchar('*');
	my_putstr(tab[1]);
	my_putstr(" : Color ");
	my_putstr(tab[2]);
	my_putstr(" :\n");
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
}

void display_form(int fd)
{
	char *s = line(fd);

	while (s) {
		my_putstr(s);
		free(s);
		s = line(fd);
	}
}

void display_tetriminos(char *nam)
{
	int fd;
	char *name = my_strcat("tetriminos/", nam);

	if ((fd = open(name, O_RDONLY)) == -1)
		exit(84);
	my_putstr("Tetriminos : Name ");
	display_name(name);
	if (check_all_info(name) == -1)
		my_putstr("Error\n");
	else {
		get_all_info(fd);
		display_form(fd);
	}
	close(fd);
	free(name);
}
