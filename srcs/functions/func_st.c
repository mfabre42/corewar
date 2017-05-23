/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:34:09 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/24 01:33:10 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	direct_store2(t_map *map, t_process *proc, t_bin *bin, int *result)
{
	if (OCP.param2 == 'R')
	{
		if (!is_reg(hex_to_int(0x00, 0x00, 0x00, ARENA[(POS + 3)
		% MEM_SIZE]), proc, 4))
			return (0);
		proc->reg[(int)ARENA[(POS + 3) % MEM_SIZE] - 1] =
		proc->reg[REG_NBR - 1];
		proc->pc = proc->pc + 4;

	}
	else
	{
		*result = POS + (short)hex_to_int(0x00, 0x00,
			ARENA[(POS + 3) % MEM_SIZE], ARENA[(POS + 4) % MEM_SIZE]) % IDX_MOD;
		place_in_arena(map, *result, proc->reg[REG_NBR - 1]);
		proc->pc = proc->pc + 5;
	}
	return (1);
}

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
		PREG_NBR = (int)ARENA[(PPOS + 2) % MEM_SIZE];
		if (!is_reg(PREG_NBR, proc, 4))
			return ;
		if (direct_store2(map, proc, &bin, &result) == 0)
			return;
	}
}
