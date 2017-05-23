/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:15:10 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/24 01:26:43 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		indirect_store3(t_map *map, t_process *proc, t_bin *bin, int *result)
{
	else if ((POCP.param2 == 'D' || POCP.param2 == 'I') && POCP.param3 == 'D')
	{
		result = (short)hex_to_int(0x00, 0x00, ARENA[(PPOS + 3) % MEM_SIZE], ARENA[(PPOS + 4) % MEM_SIZE]);
		result += (short)hex_to_int(0x00, 0x00, ARENA[(PPOS + 5) % MEM_SIZE], ARENA[(PPOS + 6) % MEM_SIZE]);
		proc->pc = proc->pc + 7;
	}
	else if ((POCP.param2 == 'D' || POCP.param2 == 'I') && POCP.param3 == 'R')
	{
		if (!is_reg((int)ARENA[(PPOS + 5) % MEM_SIZE], proc, 6))
			return ;
		result = (short)hex_to_int(0x00, 0x00, ARENA[(PPOS + 3) % MEM_SIZE], ARENA[(PPOS + 4) % MEM_SIZE]);
		result += proc->reg[(int)ARENA[(PPOS + 5) % MEM_SIZE] - 1];
		proc->pc = proc->pc + 6;
	}
}

int		indirect_store2(t_map *map, t_process *proc, t_bin *bin, int *result)
{
	if (OCP.param2 == 'R' && OCP.param3 == 'D')
	{
		if (!is_reg((int)ARENA[(POS + 3) % MEM_SIZE], proc, 6))
			return 0;
		*result = proc->reg[(int)ARENA[(POS + 3) % MEM_SIZE] - 1];
		*result += (short)hex_to_int(0x00, 0x00, ARENA[(POS + 4) %
			MEM_SIZE], ARENA[(POS + 5) % MEM_SIZE]);
		proc->pc = proc->pc + 6;
	}
	else if (OCP.param2 == 'R' && OCP.param3 == 'R')
	{
		if (!is_reg((int)ARENA[(POS + 3) % MEM_SIZE], proc, 5)
			|| !is_reg((int)ARENA[(POS + 4) % MEM_SIZE], proc, 5))
			return 0;
		*result = proc->reg[(int)ARENA[(POS + 3) % MEM_SIZE] - 1];
		*result += proc->reg[(int)ARENA[(POS + 4) % MEM_SIZE] - 1];
		proc->pc = proc->pc + 5;
	}
	return 1;
}

void	indirect_store(t_map *map, t_process *proc)
{
	int		result;
	t_bin	bin;

	if (proc->do_funk == 1)
		do_funk(proc, 23, 11, 0);
	else
	{
		do_funk(proc, 0, 0, 1);
		bin = init_bin(map, proc);
		if (!is_reg((int)ARENA[(PPOS + 2) % MEM_SIZE], proc, 5))
			return ;
		PREG_NBR = (int)ARENA[(PPOS + 2) % MEM_SIZE];
		if (POCP.param2 == 'R' && (POCP.param3 == 'D' || POCP.param3 == 'R'))
		{
			if (indirect_store2(map, proc, &bin, &result) == 0)
				return ;
		}
		else if ((POCP.param2 == 'D' || POCP.param2 == 'I') && (POCP.param3 == 'D' || POCP.param3 == 'R'))
		{
			if (indirect_store2(map, proc, &bin, &result) == 0)
				return ;
			result = (short)hex_to_int(0x00, 0x00, ARENA[(PPOS + 3) % MEM_SIZE], ARENA[(PPOS + 4) % MEM_SIZE]);
			result += (short)hex_to_int(0x00, 0x00, ARENA[(PPOS + 5) % MEM_SIZE], ARENA[(PPOS + 6) % MEM_SIZE]);
			proc->pc = proc->pc + 7;
		}
		else if ((POCP.param2 == 'D' || POCP.param2 == 'I') && POCP.param3 == 'R')
		{
			if (!is_reg((int)ARENA[(PPOS + 5) % MEM_SIZE], proc, 6))
				return ;
			result = (short)hex_to_int(0x00, 0x00, ARENA[(PPOS + 3) % MEM_SIZE], ARENA[(PPOS + 4) % MEM_SIZE]);
			result += proc->reg[(int)ARENA[(PPOS + 5) % MEM_SIZE] - 1];
			proc->pc = proc->pc + 6;
		}
		else
		{
			proc->pc = proc->pc + 5;
			return ;
		}
		place_in_arena(map, (PPOS + result) % MEM_SIZE, proc->reg[PREG_NBR - 1]);
	}
}
