# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:51:15 by aleveque          #+#    #+#              #
#    Updated: 2017/05/31 18:49:30 by acoupleu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRCDIR = src

OBJDIR = obj

SRC = ft_bzero.c ft_isdigit.c\
	  ft_itoa.c\
	  ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c\
	  ft_memalloc.c\
	  ft_strcat.c\
	  ft_strstr.c ft_strdup.c ft_strcmp.c ft_atoi.c ft_putchar.c ft_strlen.c

OBJ = $(SRC:.c=.o)

OBJP = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

SRCPATH = $(addprefix $(SRCDIR)/, $(SRC))

FLAG = -Wall -Werror -Wextra

all: obj $(NAME)

re: fclean all

obj/%.o: $(SRCDIR)/%.c
	@$(CC) -c -o $@ $^

obj:
	@echo "\033[1;32mcompiling libft obj"
	@mkdir -p obj

$(NAME): $(OBJP)
	@echo "\033[1;34mcompiling libft"
	@ar rc $@ $^

clean:
	@echo "\033[1;31mcleaning libft"
	@rm -rf obj

fclean: clean
	@echo "\033[1;31mfclean libft.a"
	@rm -f $(NAME)
