/*
** EPITECH PROJECT, 2018
** check.c
** File description:
** check
*/

#include "main.h"

void check_size(char *av)
{
	int i;
	int j = 0;
	char *s = malloc(sizeof(char) * my_strlen(av));

	for (i = 0; av[i]; i++) {
		if (av[i] == '*' && char_to_int(s) == 0)
			exit(84);
		else if (av[i] != '*' && (av[i] < 48 || av[i] > 57))
			exit(84);
		if (av[i] == '*')
			j = 0;
		else {
			s[j] = av[i];
			s[j + 1] = '\0';
			j++;
		}
	}
	if (char_to_int(s) == 0)
		exit(84);
	free(s);
}

void check_key(char *av)
{
	if (my_strlen(av) > 2 && my_strcmp(av, "^EOA") != 1
		&& my_strcmp(av, "^EOB") != 1 && my_strcmp(av, "^EOC") != 1
		&& my_strcmp(av, "^EOD") != 1)
		exit(84);
}

int check_arg(char **av, int nb)
{
	int i;

	for (i = 0; my_strcmp(flag_tab[i].flag, av[nb]) != 1
		     && my_strcmp(flag_tab[i].lflag, av[nb]) != 1
		     && i < 10; i++);
	if (i > 9 && my_strcmp(av[nb], "--map-size") != 1)
		exit(84);
	else {
		if (my_strcmp(av[nb], "--map-size") == 1) {
			nb += 1;
			check_arg_size(av[nb]);
			check_size(av[nb]);
		} else
			nb = check_arg_key(av, nb, i);
	}
	return (nb);
}

void check_prompt(char **av)
{
	int i;

	for (i = 0; av[i]; i++)
		i = check_arg(av, i);
}

void check_all_flag(void)
{
	int i;
	int j;

	for (i = 0; i < 7; i++)
		for (j = 0; j < 7; j++)
			if (my_strcmp(flag_tab[i].key, flag_tab[j].key) == 1
				&& i != j)
				exit(84);
}
