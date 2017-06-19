CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = -L./libft -lft
MAKE = make
NAME1 = checker
NAME2 = push_swap

SRCS += ./src/main.c
SRCS += ./src/sort_int.c

INC += ./inc/push_swap.h

OBJ = $(SRCS:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): libft $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIB) $(SRCS) -o $@

$(NAME2): libft $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIB) $(SRCS) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re:	fclean all

.PHONY: libft
libft:
	cd ./libft && $(MAKE)
