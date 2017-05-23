# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:51:15 by aleveque          #+#    #+#              #
#    Updated: 2017/05/16 18:24:45 by mafabre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRCDIR = src

OBJDIR = obj

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	  ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
	  ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
	  ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
	  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
	  ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c\
	  ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
	  ft_strlen.c get_next_line.c\
	  ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
	  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c\
	  ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c\
	  ft_lstaddend.c ft_strlen.c ft_isblank.c \
	  ft_count_word.c

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
