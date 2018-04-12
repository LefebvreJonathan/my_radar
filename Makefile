##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= my_radar

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c \
	  ./src/set_array.c \
	  ./src/set_in_struct.c \
	  ./src/radar.c \
	  ./src/landing.c \
	  ./src/position.c \
	  ./src/init_object.c \
	  ./src/print_text.c \
	  ./src/destroy_game.c \
	  ./src/manage_plane.c \
	  ./src/SAT.c \
	  ./src/min_and_max.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 make -C lib/my
	 gcc -o $(NAME) $(OBJS) $(CFLAGS) -lc_graph_prog -lm -Llib/my/ -lmy

clean:
	make clean -C lib/my
	rm -f $(OBJS)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean all
	make re -C lib/my

.PHONY: all clean fclean re
