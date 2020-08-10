NAME = printf

SRC = ft_printf \
		parsing \
		flags \
		main

OBJ = $(addsuffix .o, $(SRC))

OBJ_DIR = objects

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

INC = includes

all: obj_dir $(LIB) $(NAME)
		$(CC) $(OBJ) -L$(dir $(LIB)) -lft -o $(NAME)

obj_dir:
		mkdir -p $(OBJ_DIR)

$(LIB): 
		make -sC $(dir $(LIB))

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $@

$(OBJ_DIR)/%.o: %.c $(INC)
		$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all, obj_dir, fclean, clean, re
