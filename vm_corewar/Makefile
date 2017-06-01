# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/10 15:31:11 by mafabre           #+#    #+#              #
#    Updated: 2017/05/31 18:49:15 by acoupleu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					=	gcc
NAME				=	corewar
FLAGS				=	-Wall -Werror -Wextra
LIB					=	$(LIBFT) $(LIBFTPRINTF)
LIBFT_PATH			=	lib_vm/
LIBFT				=	$(LIB_PATH)libft.a
LIBFTPRINTF_PATH	=	ft_printf/
LIBFTPRINTF			=	$(LIBFTPRINTF_PATH)libftprintf.a
LIB_LINK			=	-L $(LIBFT_PATH) -lft -L $(LIBFTPRINTF_PATH) -lftprintf
INCLUDES			=	-I $(LIBFT_PATH) -I $(LIBFTPRINTF_PATH) -I ./includes
SRCS				=	srcs/main.c srcs/save_params.c srcs/save_file.c srcs/init_arena.c \
						srcs/calc_ocp.c srcs/hex_to_int.c srcs/place_in_arena.c \
						srcs/init_process.c srcs/cp_process.c srcs/corewar.c srcs/cycle_to_die.c \
						srcs/kill_player.c srcs/func_errors.c srcs/is_alive.c

FUNCTIONS			=	srcs/functions/func_add.c srcs/functions/func_aff.c srcs/functions/func_and.c	\
						srcs/functions/func_fork.c srcs/functions/func_ldi.c srcs/functions/func_lfork.c	\
						srcs/functions/func_live.c srcs/functions/func_lld.c srcs/functions/func_lldi.c	\
						srcs/functions/func_load.c srcs/functions/func_or.c srcs/functions/func_st.c	\
						srcs/functions/func_sti.c srcs/functions/func_sub.c srcs/functions/func_xor.c	\
						srcs/functions/func_zjmp.c srcs/functions/fail_func.c

VISUALISATEUR		=	srcs/visu/visu.c srcs/visu/init_visu.c srcs/visu/info_visu.c

OBJS				=	$(SRCS:srcs/%.c=obj/%.o)
OBJS_FUNC			=	$(FUNCTIONS:srcs/functions/%.c=obj/%.o)
OBJS_VISU			=	$(VISUALISATEUR:srcs/visu/%.c=obj/%.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[34m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	[ $(C_GOOD)OK$(C_NO) ]
OK				=	[ $(C_OK)OK$(C_NO) ]


all: obj $(LIB) $(NAME)

$(NAME): $(OBJS) $(OBJS_FUNC) $(OBJS_VISU)
	$(CC) $(FLAGS) -lncurses -o $@ $(OBJS) $(OBJS_FUNC) $(OBJS_VISU) $(LIB_LINK)
	@echo "Compiling" $(NAME) "\t\t" $(SUCCESS)

$(LIB):
	@make -C $(LIBFT_PATH)
	@make -C $(LIBFTPRINTF_PATH)

obj:
	@mkdir -p obj
	@mkdir -p obj/functions

obj/%.o: srcs/%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Linking" $< "\t" $(OK)

obj/%.o: srcs/functions/%.c
	@$(CC) $(FLAGS) $(INCLUDES) -I ../includes/corewar.h -c -o $@ $<
	@echo "Linking" $< "\t" $(OK)

obj/%.o: srcs/visu/%.c
	@$(CC) $(FLAGS) $(INCLUDES) -I ../includes/corewar.h -c -o $@ $<
	@echo "Linking" $< "\t" $(OK)

clean:
	@rm -rf obj
	@make -C $(LIBFT_PATH) clean
	@make -C $(LIBFTPRINTF_PATH) clean
	@echo "Cleaning" $(NAME) "\t\t" $(OK)

fclean:
	@rm -rf obj
	@echo "Cleaning" $(NAME) "\t\t" $(OK)
	echo $(OBJS)
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(LIBFTPRINTF_PATH) fclean
	@echo "Delete" $(NAME) "\t\t\t" $(OK)

re: fclean all
