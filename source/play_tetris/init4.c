/*
** EPITECH PROJECT, 2018
** init4.c
** File description:
** init4
*/

#include "main.h"

int check_tetrimino2(char **tab, int i)
{
	int j;

	for (j = i; tab[j + 1]; j++)
		tab[j] = my_strcpy(tab[j + 1]);
	return (j);
}
