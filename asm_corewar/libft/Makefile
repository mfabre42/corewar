# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:51:15 by aleveque          #+#    #+#              #
#    Updated: 2017/05/30 19:44:16 by acoupleu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRCDIR = src

OBJDIR = obj

SRC =   ft_itoa.c ft_lstadd.c ft_lstnew.c ft_strchr.c ft_strcmp.c \
		ft_strcpy.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c \
		ft_strsplit.c ft_toupper.c get_next_line.c ft_count_word.c \
		ft_strnew.c ft_strsub.c ft_atoi.c ft_strcat.c ft_memalloc.c

OBJ = $(SRC:.c=.o)

OBJP = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

SRCPATH = $(addprefix $(SRCDIR)/, $(SRC))

FLAG = -Wall -Werror -Wextra

all: $(OBJDIR) $(NAME)

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c -o $@ $^

$(OBJDIR):
	@echo "\033[1;32mcompiling libft obj"
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJP)
	@echo "\033[1;34mcompiling libft"
	@ar rc $@ $^

clean:
	@echo "\033[1;31mcleaning libft"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "\033[1;31mfclean libft.a"
	@rm -f $(NAME)
