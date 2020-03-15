/*
** EPITECH PROJECT, 2018
** init.h
** File description:
** init header
*/

#ifndef INIT_H_
#define INIT_H_

char **create_map(int, int, char);
int get_size(char *, int);
void set_line(char *, char *, int);
char **get_parameters_map(map_t *, char *);
char **create_tetrimino(map_t *, char **, int);
map_t *init_map(char **, option_t *);
int init_all(WINDOW *, int);
int set_one_key(int);
keys_t init_all_key(void);
option_t init_option(WINDOW *);
int check_tetrimino2(char **, int);

#endif
