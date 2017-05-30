# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/10 15:31:11 by mafabre           #+#    #+#              #
#    Updated: 2017/05/30 19:24:38 by aleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = coreware

all:
	make -C vm_corewar
	make -C asm_corewar
	@cp vm_corewar/corewar .
	@cp asm_corewar/asm .

clean:
	@make -C vm_corewar clean
	@make -C asm_corewar clean

fclean:
	@make -C vm_corewar fclean
	@make -C asm_corewar fclean
	rm -f corewar
	rm -f asm

re: fclean all
