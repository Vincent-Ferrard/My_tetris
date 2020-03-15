/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct header
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct flag_s {
	char *flag;
	char *lflag;
	int nb_args;
	char *key;
} flag_t;

extern flag_t flag_tab[];

typedef struct map_s {
        char **tab;
        int line;
        int column;
} map_t;

typedef struct keys_s {
        int k_left;
        int k_right;
        int k_turn;
        int k_drop;
        int k_pause;
        int k_quit;
} keys_t;

typedef struct option_s {
        int line;
        int level;
        int score;
	int past;
	int next;
	int map_x;
	int map_y;
} option_t;

#endif
