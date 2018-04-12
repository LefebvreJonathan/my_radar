NAME	= libmy.a

RM	= rm -f

SRCS	= ./add_to_array.c \
	  ./free_array.c \
	  ./intlen.c \
	  ./my_arrayintlen.c \
	  ./my_arraylen.c \
	  ./my_get_nbr.c \
	  ./my_strcat.c \
	  ./my_strcpy.c \
	  ./my_strlen.c \
	  ./array_len.c \
	  ./my_strdup.c \
	  ./free_array.c \
	  ./get_next_line.c \
	  ./add_to_array.c \
	  ./my_get_nbr.c \
	  ./str_to_word_array.c \
	  ./my_strcmp.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ../../include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
