/*
** EPITECH PROJECT, 2018
** tetriminos.h
** File description:
** tetriminos header
*/

#ifndef TETRIMINOS_H_
#define TETRIMINOS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void display_name(char *);
int check_all_info(char *);
void get_all_info(int);
void display_form(int);
void display_tetriminos(char *);

char *line(int);
int nb_args(char *);
char **my_str_to_word_array(char *);

int check_nb_point(char *);
int get_all_tetriminos(char *);
int nb_file(void);
int check_switch(char *, char *);
int order_tab2(char **, int, int);
char **order_tab(char **);
char **parse_folder(void);

#endif
