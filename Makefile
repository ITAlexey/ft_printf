NAME = printf

SRC = ft_printf \
		parsing \
		flags \
		generate_output \
		main

OBJ = $(addsuffix .o, $(SRC))

OBJ_DIR = objects

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

INC = inc

all: $(NAME)

$(NAME): obj_dir $(LIB) $(OBJ)
		$(CC) $(OBJ) -L$(dir $(LIB)) -lft -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(INC) libft/includes
		$(CC) $(CFLAGS) -o $@ -c $< -I$(INC) -I$(addsuffix $(INC)ludes, $(dir LIB))

obj_dir:
		mkdir -p $(OBJ_DIR)

$(LIB): 
		make -sC $(dir $(LIB))


clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all, obj_dir, fclean, clean, re
