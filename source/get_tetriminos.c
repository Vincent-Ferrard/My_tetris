/*
** EPITECH PROJECT, 2018
** get_tetriminos.c
** File description:
** get_tetriminos
*/

#include <sys/types.h>
#include "main.h"

int nb_file(void)
{
	DIR *dirp = opendir("tetriminos");
	int count = 0;

	if (dirp == NULL)
		exit(84);
	while (readdir(dirp) != NULL)
		count++;
	closedir(dirp);
	return (count + 1);
}

int check_switch(char *s, char *s2)
{
	int i;

	for (i = 0; s[i] && s2[i]; i++) {
		if (s[i] > s2[i])
			return (1);
		else if (s[i] < s2[i])
			return (0);
	}
	return (0);
}

int order_tab2(char **tab, int i, int check)
{
	int j;
	char *s = NULL;

	if (check_switch(tab[i - 1], tab[i]) == 1) {
		s = malloc(sizeof(char) * my_strlen(tab[i - 1]));
		for (j = 0; tab[i - 1][j]; j++)
			s[j] = tab[i - 1][j];
		s[j] = '\0';
		tab[i - 1] = malloc(sizeof(char) * my_strlen(tab[i]));
		for (j = 0; tab[i][j]; j++)
			tab[i - 1][j] = tab[i][j];
		tab[i - 1][j] = '\0';
		tab[i] = malloc(sizeof(char) * my_strlen(s));
		for (j = 0; s[j]; j++)
			tab[i][j] = s[j];
		tab[i][j] = '\0';
		check = 1;
		free(s);
	}
	return (check);
}

char **order_tab(char **tab)
{
	int i;
	int check = 1;

	while (check == 1) {
		check = 0;
		for (i = 1; tab[i]; i++)
			check = order_tab2(tab, i, check);
	}
	return (tab);
}

char **parse_folder(void)
{
	DIR *dirp = opendir("tetriminos");
	struct dirent *s_dir;
	char **tab = malloc(sizeof(char *) * nb_file());
	int i = 0;

	if (dirp == NULL)
		exit(84);
	while ((s_dir = readdir(dirp)) != NULL)
		if (get_all_tetriminos(s_dir->d_name) != 0) {
			tab[i] = malloc(
				sizeof(char) * my_strlen(s_dir->d_name));
			tab[i] = my_strcpy(s_dir->d_name);
			i++;
		}
	tab[i] = NULL;
	if (i == 0)
		exit(84);
	tab = order_tab(tab);
	closedir(dirp);
	return (tab);
}
