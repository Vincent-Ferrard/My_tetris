/*
** EPITECH PROJECT, 2018
** check2.c
** File description:
** check2
*/

#include "main.h"

void check_arg_size(char *s)
{
	if (s == NULL)
		exit(84);
}

int check_arg_key(char **av, int nb, int i)
{
	for (int j = 0; j < flag_tab[i].nb_args; j++) {
		nb += 1;
		if (av[nb] == NULL)
			exit(84);
		check_key(av[nb]);
	}
	return (nb);
}
