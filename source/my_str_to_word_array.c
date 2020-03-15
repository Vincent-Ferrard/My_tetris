/*
** EPITECH PROJECT, 2018
** space.c
** File description:
** space
*/

#include "main.h"

int nb_args(char *str)
{
	int nbr_args = 1;

	if (str == NULL)
		return (1);
	for (int i = 0; str[i]; i++)
		if (str[i] == ' ')
			nbr_args++;
	return (nbr_args + 1);
}

char **my_str_to_word_array(char *str)
{
	char **interact = malloc(sizeof(char *) * nb_args(str));
	int j = 0;
	int k = 0;

	if (str == NULL)
		return (NULL);
	for (int h = 0; h < nb_args(str); h++)
		interact[h] = malloc(sizeof(char) * (my_strlen(str) + 1));
	for (int i = 0; str[i] && str[i] != '\n'; i++)
		if (str[i] == ' ') {
			interact[j][k] = '\0';
			j++;
			k = 0;
		} else {
			interact[j][k] = str[i];
			k++;
		}
	interact[j][k] = '\0';
	interact[j + 1] = NULL;
	free(str);
	return (interact);
}
