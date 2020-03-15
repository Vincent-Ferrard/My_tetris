/*
** EPITECH PROJECT, 2018
** flag.h
** File description:
** flag
*/

#ifndef FLAG_H_
#define FLAG_H_

char put_in(char, char, int *, int *);
char **put_new_av(char **, char **);
char **set_new_av(char **);
int set_key(char **, int, int);
void set_flag(char **);

int check_str(char *, char, int);
int count_nb_args(char **);

#endif
