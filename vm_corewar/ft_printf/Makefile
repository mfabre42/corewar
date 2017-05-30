# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 16:19:02 by aleveque          #+#    #+#              #
#    Updated: 2017/01/17 13:03:56 by aleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC2 = writestr.c printf_putstr.c printf_putchar.c printf_putnbr.c\
	   ft_putstr_printf.c printf_puthex.c printf_putoct.c printf_puthexa.c\
	   printf_putpoint.c printf_putwchar.c ft_putwstr.c\
	   ft_putwchar.c ft_itoa_llu.c optn_minus.c optn_nbr.c optn_oct.c\
	   optn_plus.c optn_point.c optn_space.c optn_zero.c ft_conv.c ft_conv2.c\
	   ft_convint.c ft_convint2.c ft_convint3.c ft_printconv.c ft_castperc.c\
	   ft_printf.c wheel_of_destiny.c printf_option.c ft_charwlen.c

SRCLIB = ft_atoi.c ft_isdigit.c\
	  ft_strcmp.c\
	  ft_putchar.c\
	  ft_strnstr.c ft_strdup.c\
	  ft_strlen.c\
	  ft_tolower.c ft_toupper.c\
	  ft_nbrlen_base.c ft_itoa_base.c ft_strjoin.c

SRCPATH = $(addprefix write/, $(SRC2))

LIBPATH = $(addprefix libft/, $(SRCLIB))

OBJ2 = $(SRC2:.c=.o)

OBJLIB = $(SRCLIB:.c=.o)

LIB = libft/libft.a

$(NAME):
	gcc -c $(SRCPATH) $(LIBPATH)
	ar rc $(NAME) $(OBJ2) $(OBJLIB)

all: $(NAME)

clean:
	rm -f $(OBJ2) $(OBJLIB)

fclean: clean
	rm -f $(NAME)

re: fclean all
