# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:51:15 by aleveque          #+#    #+#              #
<<<<<<< HEAD:libft/Makefile
#    Updated: 2017/05/30 18:48:14 by acoupleu         ###   ########.fr        #
=======
#    Updated: 2017/05/30 18:44:31 by aleveque         ###   ########.fr        #
>>>>>>> c2c7cebb3f4d81b106b523c8b00214db2d0416e0:vm_corewar/libft/Makefile
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
