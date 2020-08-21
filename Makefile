NAME = printf

SRC = ft_printf \
		parsing \
		flags \
		generate_output \
		parsing_types \
		record_flags \
		main

VPATH = src

OBJ_DIR = objects

OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC)))

CC = gcc

CFLAGS = -Wall -Wextra

LIB = libft/libft.a

INC = includes

all: $(NAME)

$(NAME): obj_dir $(LIB) $(OBJ)
		$(CC) $(OBJ) -L$(dir $(LIB)) -lft -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(INC) libft/includes
		$(CC) $(CFLAGS) -o $@ -c $< -I$(INC) -I$(addsuffix $(INC), $(dir $(LIB)))

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
