/*
** EPITECH PROJECT, 2018
** utils3.c
** File description:
** utils3
*/

#include "main.h"

int number_isneg(int nb)
{
	if (nb < 0) {
		write(1, "-", 1);
		nb = -nb;
	}
	return (nb);
}

int my_put_nbr(int nb)
{
	char c[9];
	char c2[9];
	int i = 0;
	int j = 0;

	nb = number_isneg(nb);
	while (nb > 0 || i == 0) {
		c[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	c[i] = '\0';
	for (j = 0; c[j] != '\0'; j++)
		c2[j] = c[i - j - 1];
	c2[j] = '\0';
	my_putstr(c2);
	return (0);
}
