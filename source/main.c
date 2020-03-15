/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "main.h"
#include <sys/ioctl.h>

flag_t flag_tab[] =
{
	{"-L", "--level", 1, "1"},
	{"-l", "--key-left", 1, "^EOD"},
	{"-r", "--key-right", 1, "^EOC"},
	{"-t", "--key-turn", 1, "^EOA"},
	{"-d", "--key-drop", 1, "^EOB"},
	{"-q", "--key-quit", 1, "q"},
	{"-p", "--key-pause", 1, " "},
	{"-w", "--without-next", 0, "0"},
	{"-D", "--debug", 0, "0"},
	{"", "--help", 0, "0"},
	{"", "--map-size", 1, "20*10"},
	{0, 0, 0, 0}
};

void display_key(char *str, char *lflag)
{
	int i;

	my_putstr(str);
	my_putchar(' ');
	for (i = 0; my_strcmp(flag_tab[i].lflag, lflag) != 1; i++);
	if (my_strcmp(flag_tab[i].key, " ") == 1)
		my_putstr("(space)");
	else {
		if (my_strcmp(flag_tab[i].key, "1") == 1 && i > 0)
			my_putstr("No");
		else if (my_strcmp(flag_tab[i].key, "0") == 1 && i > 0)
			my_putstr("Yes");
		else
			my_putstr(flag_tab[i].key);
	}
	my_putchar('\n');
}

void display_all(char **tab)
{
	int i;

	my_putstr("*** DEBUG MODE ***\n");
	display_key("Key Left :", "--key-left");
	display_key("Key Right :", "--key-right");
	display_key("Key Turn :", "--key-turn");
	display_key("Key Drop :", "--key-drop");
	display_key("Key Quit :", "--key-quit");
	display_key("Key Pause :", "--key-pause");
	display_key("Next :", "--without-next");
	display_key("Level :", "--level");
	display_key("Size :", "--map-size");
	for (i = 0; tab[i]; i++);
	my_putstr("Tetriminos : ");
	my_put_nbr(i);
	my_putchar('\n');
	for (i = 0; tab[i]; i++)
		display_tetriminos(tab[i]);
	my_putstr("Press any key to start Tetris\n");
}

void help(char *name_exe)
{
	int fd = open("utils/help", O_RDONLY);
	char *s = line(fd);

	my_putstr("Usage: ");
	my_putstr(name_exe);
	my_putstr(" [options]\n");
	while (s) {
		my_putstr(s);
		free(s);
		s = line(fd);
	}
	my_putchar('\n');
	close(fd);
}

int check_flag(char *lflag)
{
	int j;

	for (j = 0; my_strcmp(flag_tab[j].lflag, lflag) != 1
		&& flag_tab[j].lflag; j++);
	if (my_strcmp(flag_tab[j].key, "1") == 1)
		return (1);
	else
		return (0);
}

int main(int ac, char **av)
{
	char *name_exe = av[0];
	char **tab = parse_folder();

	if (ac > 1) {
		av = set_new_av(av);
		check_prompt(av);
		set_flag(av);
		check_all_flag();
	}
	if (check_flag("--help") == 1) {
		help(name_exe);
		return (0);
	}
	if (check_flag("--debug") == 1)
		display_all(tab);
	else
		tetris_play(tab);
	for (int i = 0; av[i]; i++)
		free(av[i]);
	return (0);
}
