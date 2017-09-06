CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = -L./libft -lft
MAKE = make
NAME1 = checker
NAME2 = push_swap

SRCS2 += ./src/push_swap/main.c
SRCS2 += ./src/push_swap/parsing.c
SRCS2 += ./src/push_swap/sort_int.c
SRCS2 += ./src/push_swap/rotate.c
SRCS2 += ./src/push_swap/reverse_rotate.c
SRCS2 += ./src/push_swap/swap.c
SRCS2 += ./src/push_swap/push.c
SRCS2 += ./src/push_swap/reset.c
SRCS2 += ./src/push_swap/utils.c

INC += ./inc/push_swap.h

OBJ2 = $(SRCS2:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): libft $(OBJ1) $(INC)
	$(CC) $(CFLAGS) $(LIB) $(SRCS1) -o $@

$(NAME2): libft $(OBJ2) $(INC)
	$(CC) $(CFLAGS) $(LIB) $(SRCS2) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ1) $(OBJ2)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re:	fclean all

.PHONY: libft
libft:
	cd ./libft && $(MAKE)
