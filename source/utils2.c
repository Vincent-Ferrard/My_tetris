/*
** EPITECH PROJECT, 2018
** utils2.c
** File description:
** utils2
*/

#include "main.h"

char *set_char(char *dest, char *dest2)
{
	int i;
	int k = 0;

	for (i = 0; dest[i]; i++);
	for (int j = i - 1; j >= 0; j--) {
		dest2[k] = dest[j];
		k++;
	}
	dest2[k] = '\0';
	return (dest2);
}

char *int_to_char(int nb)
{
	char *dest = malloc(sizeof(char) * 3);
	char *dest2 = malloc(sizeof(char) * 3);
	int i = 0;

	if (nb == 0) {
		dest[i] = '0';
		dest[i + 1] = '\0';
	} else {
		for (i = 0; nb > 0; i++) {
			dest[i] = (nb % 10) + 48;
			nb /= 10;
		}
		dest[i] = '\0';
	}
	dest2 = set_char(dest, dest2);
	free(dest);
	return (dest2);
}

int char_to_int(char *s)
{
	int i;
	int nb = 0;

	for (i = 0; s[i]; i++)
		nb = nb * 10 + s[i] - 48;
	return (nb);
}

char *my_strcat(char *str, char *str2)
{
	char *newstr = malloc(
		sizeof(char) * (my_strlen(str) + my_strlen(str2) + 1));
	int i;
	int j;

	for (i = 0; str[i]; i++)
		newstr[i] = str[i];
	for (j = 0; str2[j]; j++) {
		newstr[i] = str2[j];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
