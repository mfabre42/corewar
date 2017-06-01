/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:31:28 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/01 18:51:19 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		direct_load2(t_map *map, t_process *proc, t_bin *bin)
{
	if (OCP.param1 == 'I')
	{
		if (!is_reg((int)ARENA[(POS + 4) % MEM_SIZE], proc, 5))
			return (0);
		REG_NBR = (int)ARENA[(POS + 4) % MEM_SIZE];
		proc->reg[REG_NBR - 1] = read_in_arena(map, POS +
			(short)hex_to_int(0x00, 0x00, ARENA[(POS + 2) % MEM_SIZE],
			ARENA[(POS + 3) % MEM_SIZE]) % IDX_MOD);
		proc->pc = proc->pc + 5;
	}
	else
	{
		proc->pc = proc->pc + 5;
		return (0);
	}
	return (1);
}

void			direct_load(t_map *map, t_process *proc)
{
	t_bin	bin;

	if (proc->do_funk == 1)
		do_funk(proc, 3, 2, 0);
	else
	{
		do_funk(proc, 0, 0, 1);
		bin = init_bin(map, proc);
		if (POCP.param1 == 'D')
		{
			if (!is_reg((int)ARENA[(PPOS + 6) % MEM_SIZE], proc, 7))
				return ;
			PREG_NBR = (int)ARENA[(PPOS + 6) % MEM_SIZE];
			proc->reg[PREG_NBR - 1] = hex_to_int(ARENA[(PPOS + 2) % MEM_SIZE],
				ARENA[(PPOS + 3) % MEM_SIZE],
				ARENA[(PPOS + 4) % MEM_SIZE], ARENA[(PPOS + 5) % MEM_SIZE]);
			proc->pc = proc->pc + 7;
		}
		else
		{
			if (direct_load2(map, proc, &bin) == 0)
				return ;
		}
		proc->carry = !proc->reg[PREG_NBR - 1];
	}
}
