/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:34:09 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/24 01:24:12 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	direct_store(t_map *map, t_process *proc)
{
	t_bin	bin;
	int		result;

	if (proc->do_funk == 1)
		do_funk(proc, 3, 3, 0);
	else
	{
		do_funk(proc, 0, 0, 1);
		bin = init_bin(map, proc);
		PREG_NBR = (int)map->arena[(PPOS + 2) % MEM_SIZE];
		if (!is_reg(reg_nbr, proc, 4))
			return ;
		if (ocp.param2 == 'R')
		{
			if (!is_reg(hex_to_int(0x00, 0x00, 0x00, map->arena[(PPOS + 3)
			% MEM_SIZE]), proc, 4))
				return ;
			proc->reg[(int)map->arena[(PPOS + 3) % MEM_SIZE] - 1] =  proc->reg[reg_nbr - 1];
			proc->pc = proc->pc + 4;

		}
		else
		{
			result = PPOS + (short)hex_to_int(0x00, 0x00,
				map->arena[(PPOS + 3) % MEM_SIZE], map->arena[(PPOS + 4) % MEM_SIZE]) % IDX_MOD;;
			place_in_arena(map, result, proc->reg[reg_nbr - 1]);
			proc->pc = proc->pc + 5;
		}
	}
}
