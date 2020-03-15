/*
** EPITECH PROJECT, 2018
** main.h
** File description:
** main header
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <ncurses.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>

#include "struct.h"
#include "check.h"
#include "display.h"
#include "flag.h"
#include "init.h"
#include "tetriminos.h"
#include "utils.h"

void display_key(char *, char *);
void display_all(char **);
void help(char *);
int check_flag(char *);

char **my_strcpy_array(char **, char **);
char **set_map(char **, char **, int, int);
char **remove_line(char **, int, option_t *);
void game(map_t *, int *, int *, option_t *, char **);
void tetris_play(char **);

int event_key(keys_t *, map_t *, int, int);
void event_key2(keys_t *, int);

char **turn_tetrimino(map_t *);

char *line(int);

#endif
