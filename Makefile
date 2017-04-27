# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/10 15:31:11 by mafabre           #+#    #+#              #
#    Updated: 2017/04/27 23:13:36 by acoupleu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					=	gcc
NAME				=	corewar
FLAGS				=	-g
LIB					=	$(LIBFT) $(LIBFTPRINTF)
LIBFT_PATH			=	libft/
LIBFT				=	$(LIB_PATH)libft.a
LIBFTPRINTF_PATH	=	ft_printf/
LIBFTPRINTF			=	$(LIBFTPRINTF_PATH)libftprintf.a
LIB_LINK			=	-L $(LIBFT_PATH) -lft -L $(LIBFTPRINTF_PATH) -lftprintf
INCLUDES			=	-I $(LIBFT_PATH) -I $(LIBFTPRINTF_PATH)/includes -I ./includes
SRCS				=	srcs/main.c srcs/save_params.c srcs/save_file.c srcs/init_arena.c \
						srcs/calc_ocp.c srcs/utils/hex_to_int.c srcs/utils/is_register.c \
						srcs/utils/place_in_arena.c

OBJS				=	$(SRCS:srcs/%.c=obj/%.o)

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

$(NAME): $(LIB) $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS) $(LIB_LINK)
	@echo "Compiling" $(NAME) "\t\t" $(SUCCESS)

$(LIB):
	@make -C $(LIBFT_PATH)
	@make -C $(LIBFTPRINTF_PATH)

obj:
	@mkdir -p obj

obj/%.o: srcs/%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Linking" $< "\t" $(OK)

clean:
	@rm -rf obj
	@echo "Cleaning" $(NAME) "\t\t" $(OK)

fclean: clean
	echo $(OBJS)
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(LIBFTPRINTF_PATH) fclean
	@echo "Delete" $(NAME) "\t\t\t" $(OK)

re: fclean all
