##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## tetris
##

SRC	=	source/check.c			\
		source/check2.c			\
		source/get_tetriminos.c		\
		source/get_tetriminos2.c	\
		source/line.c			\
		source/main.c      		\
		source/my_str_to_word_array.c	\
		source/set_flag.c  		\
		source/set_flag2.c 		\
		source/tetriminos.c		\
		source/utils.c			\
		source/utils2.c			\
		source/utils3.c			\
		source/play_tetris/check.c	\
		source/play_tetris/display.c	\
		source/play_tetris/event.c	\
		source/play_tetris/init.c	\
		source/play_tetris/init2.c	\
		source/play_tetris/init3.c	\
		source/play_tetris/init4.c	\
		source/play_tetris/main.c	\
		source/play_tetris/test.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

CFLAGS	=	-I./include/ -W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
