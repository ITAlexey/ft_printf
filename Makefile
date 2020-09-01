NAME = libftprintf.a

SRC = ft_printf \
		parsing \
		generate_output \
		parsing_types \
		record_flags \
		integer_fraction_parts_calculations \
		apply_modifiers \
		convert_fraction_to_decimal \
		decimal_float_representation \
		sum \
		multiplication \

VPATH = src

OBJ_DIR = objects

OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC)))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

INC = includes

all: $(NAME)

$(NAME): obj_dir $(LIB) $(OBJ)
		@ar rc $@ $(OBJ)
		@echo "\033[32mft_printf has compiled!\033[32m"
		@ranlib $@

$(OBJ_DIR)/%.o: %.c $(INC)
		@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC) -I$(addsuffix $(INC), $(dir $(LIB)))

obj_dir:
		@mkdir -p $(OBJ_DIR)

$(LIB): 
		@make -sC $(dir $(LIB))

clean:
		@make clean -C $(dir $(LIB))
		@rm -rf $(OBJ_DIR)

fclean: clean
		@make fclean -C $(dir $(LIB))
		@rm -rf $(NAME)

re: fclean all

.PHONY: all, obj_dir, fclean, clean, re
