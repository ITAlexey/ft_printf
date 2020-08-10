# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avenonat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 01:50:31 by avenonat          #+#    #+#              #
#    Updated: 2019/10/03 16:02:18 by dshala           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = includes

HEADER = libft.h

SRCDIR = src

OBJDIR = obj

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c \
	  ft_itoa.c ft_free2darray.c ft_lstadd.c ft_lstdel.c \
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
	  ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	  ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
	  ft_strtrim.c ft_tolower.c ft_toupper.c ft_count_words.c ft_is_prime.c \
	  ft_swap.c ft_strlowcase.c ft_strupcase.c get_next_line.c

OBJECTS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): obj_dir $(OBJECTS)
		@ar rsc $@ $(OBJECTS)
		@ranlib $@ 
		@echo "libft.a has successfully compiled!"

obj_dir:
		@printf "\033[32mCompiling: Objects\033[0m\n"
		@mkdir -p $(OBJDIR) 

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)/$(HEADER)
		@$(CC) $(CFLAGS)  -o $@ -c $< -I$(INCLUDES)

clean: 
		@/bin/rm -rf $(OBJDIR)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, obj_dir, clean, fclean, re
