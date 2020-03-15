/*
** EPITECH PROJECT, 2018
** set_flag2.c
** File description:
** set_flag2
*/

#include "main.h"

int check_str(char *av, char sign, int count)
{
	int check = 0;

	for (int i = 0; av[i]; i++)
		if (av[i] == sign)
			check = 1;
	if (check == 1)
		count += 2;
	else
		count += 1;
	return (count);
}

int count_nb_args(char **av)
{
	int count = 0;

	for (int i = 1; av[i]; i++) {
		if (av[i][1] == '-' && av[i][0] == '-')
			count = check_str(av[i], '=', count);
		else if (check_str(av[i], '=', count) == count + 2)
			exit(84);
		else
			count += 1;
	}
	return (count);
}
