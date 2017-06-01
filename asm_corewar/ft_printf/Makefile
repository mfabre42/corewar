# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/10 22:21:01 by mafabre           #+#    #+#              #
#    Updated: 2017/05/31 18:50:53 by acoupleu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	libftprintf.a
FLAGS			=	-Wall -Werror -Wextra
INCLUDES		=	-I ./includes -I ../libft
SRCS			=	srcs/ft_printf.c										\
					\
					srcs/parse_flags.c 		srcs/parse_options.c			\
					\
					srcs/print_char.c		srcs/print_wchar.c				\
					srcs/print_string.c		srcs/print_wstring.c			\
					srcs/print_decimal.c	srcs/print_unsigned.c			\
					srcs/print_hex.c srcs/print_hexx.c srcs/print_octal.c	\
					srcs/print_pointer.c	srcs/print_modulo.c				\
					srcs/ft_itoa_base.c		srcs/count_print.c				\
					srcs/tools.c

OBJS			=	$(SRCS:srcs/%.c=obj/%.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[34m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	[ $(C_GOOD)OK$(C_NO) ]
OK				=	[ $(C_OK)OK$(C_NO) ]


all: obj $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib	$(NAME)
	@echo "Compiling" $(NAME) "\t\t" $(SUCCESS)


obj:
	@mkdir -p obj

obj/%.o: srcs/%.c ./includes/*.h
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Linking" $< "\t" $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf obj
	@echo "Cleaning" $(NAME) "\t\t" $(OK)

fclean: clean
	@rm -f $(NAME)
	@echo "Delete" $(NAME) "\t\t\t" $(OK)

re: fclean all
