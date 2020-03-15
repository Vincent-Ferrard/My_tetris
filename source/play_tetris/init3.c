/*
** EPITECH PROJECT, 2018
** init3.c
** File description:
** init3
*/

#include "main.h"

int set_one_key(int i)
{
	if (my_strcmp(flag_tab[i].key, "^EOA") == 1)
		return (KEY_UP);
	if (my_strcmp(flag_tab[i].key, "^EOB") == 1)
		return (KEY_DOWN);
	if (my_strcmp(flag_tab[i].key, "^EOC") == 1)
		return (KEY_RIGHT);
	if (my_strcmp(flag_tab[i].key, "^EOD") == 1)
		return (KEY_LEFT);
	return (flag_tab[i].key[0]);
}

keys_t init_all_key(void)
{
	keys_t key;

	key.k_left = set_one_key(1);
	key.k_right = set_one_key(2);
	key.k_turn = set_one_key(3);
	key.k_drop = set_one_key(4);
	key.k_quit = set_one_key(5);
	key.k_pause = set_one_key(6);
	return (key);
}

void check_map_size(WINDOW *win, option_t *option)
{
	if (option->map_x > getmaxx(win) || option->map_y > getmaxy(win)
		|| option->map_x < 10 || option->map_y < 10) {
		refresh();
		endwin();
		exit(84);
	}
}

option_t init_option(WINDOW *win)
{
	option_t option;
	char *s = malloc(sizeof(char) * (my_strlen(flag_tab[10].key)));
	int i;
	int j = 0;

	option.level = 1;
	option.line = 0;
	option.score = 0;
	for (i = 0; flag_tab[10].key[i] != '*'; i++)
		s[i] = flag_tab[10].key[i];
	s[i] = '\0';
	option.map_y = char_to_int(s);
	for (i = i + 1; flag_tab[10].key[i]; i++) {
		s[j] = flag_tab[10].key[i];
		j++;
	}
	s[j] = '\0';
	option.map_x = char_to_int(s);
	check_map_size(win, &option);
	return (option);
}
