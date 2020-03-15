/*
** EPITECH PROJECT, 2018
** check.h
** File description:
** check header
*/

#ifndef CHECK_H_
#define CHECK_H_

void check_size(char *);
void check_key(char *);
int check_arg(char **, int);
void check_prompt(char **);
void check_all_flag(void);

void check_arg_size(char *);
int check_arg_key(char **, int, int);

int check_end2(char, char, char);
int check_end(map_t *, int, int);
void check_exit(char **);
int check_column(map_t *, int, int);
char **check_line(char **, option_t *);
void check_tetrimino(char **);

#endif
