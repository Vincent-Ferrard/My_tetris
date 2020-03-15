/*
** EPITECH PROJECT, 2018
** set_flag.c
** File description:
** set_flag
*/

#include "main.h"

char put_in(char new_av, char av, int *h, int *k)
{
	if (av == '=') {
		new_av = '\0';
		h[0]++;
		k[0] = 0;
	} else if (av != '\'' && av != '{' && av != '}') {
		if (av == ',')
			new_av = '*';
		else
			new_av = av;
		k[0]++;
	}
	return (new_av);
}

char **put_new_av(char **av, char **new_av)
{
	int k = 0;
	int h = 0;

	for (int j = 1; av[j]; j++) {
		for (int i = 0; av[j][i]; i++)
			new_av[h][k] = put_in(new_av[h][k], av[j][i], &h, &k);
		new_av[h][k] = '\0';
		h++;
		k = 0;
	}
	new_av[h] = NULL;
	return (new_av);
}

char **set_new_av(char **av)
{
	char **new_av;
	int count = 0;

	count = count_nb_args(av);
	new_av = malloc(sizeof(char *) * (count + 1));
	for (int i = 0; i < count; i++)
		new_av[i] = malloc(sizeof(char) * (my_strlen(av[0]) + 1));
	return (put_new_av(av, new_av));
}

int set_key(char **av, int i, int j)
{
	if (my_strcmp(av[i], flag_tab[j].flag) == 1
		|| my_strcmp(av[i], flag_tab[j].lflag) == 1) {
		if (flag_tab[j].nb_args == 0)
			flag_tab[j].key = "1";
		else
			flag_tab[j].key = my_strcpy(av[i + 1]);
		return (1);
	} else
		return (0);
}

void set_flag(char **av)
{
	int j;

	for (int i = 0; av[i]; i++) {
		for (j = 0; flag_tab[j].flag; j++)
			if (set_key(av, i, j) == 1)
				break;
	}
}
