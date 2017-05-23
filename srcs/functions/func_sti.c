/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:15:10 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/24 00:20:15 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		indirect_store2(t_map *map, t_process *proc, t_bin *bin, int *result)
{
	if (OCP.param2 == 'R' && OCP.param3 == 'D')
	{
		if (!is_register((int)map->arena[(POS + 3) % MEM_SIZE]))
		{
			fail_func(proc, 6, 0);
			return 0;
		}
		*result = proc->reg[(int)map->arena[(POS + 3) % MEM_SIZE] - 1];
		*result += (short)hex_to_int(0x00, 0x00, map->arena[(POS + 4) %
			MEM_SIZE], map->arena[(POS + 5) % MEM_SIZE]);
		proc->pc = proc->pc + 6;
	}
	else if (OCP.param2 == 'R' && OCP.param3 == 'R')
	{
		if (!is_register((int)map->arena[(POS + 3) % MEM_SIZE])
			|| !is_register((int)map->arena[(POS + 4) % MEM_SIZE]))
		{
			fail_func(proc, 5, 0);
			return 0;
		}
		*result = proc->reg[(int)map->arena[(POS + 3) % MEM_SIZE] - 1];
		*result += proc->reg[(int)map->arena[(POS + 4) % MEM_SIZE] - 1];
		proc->pc = proc->pc + 5;
	}
	return 1;
}

void	indirect_store(t_map *map, t_process *proc)
{
	int		result;
	t_bin	*bin;

	if (proc->do_funk == 1)
		do_funk(proc, 23, 11, 0);
	else
	{
		do_funk(proc, 0, 0, 1);
		*bin = init_bin(map, proc);
		POS = proc->start + proc->pc;
		OCP = ocp_master((int)map->arena[(POS + 1) % MEM_SIZE]);
		if (!is_register((int)map->arena[(POS + 2) % MEM_SIZE]))
		{
			fail_func(proc, 5, 0);
			return ;
		}
		REG_NBR = (int)map->arena[(POS + 2) % MEM_SIZE];
		if (OCP.param2 == 'R' && (OCP.param3 == 'D' || OCP.param3 == 'R'))
			if (indirect_store2(map, proc, bin, &result) == 0)
				return ;
		else if ((OCP.param2 == 'D' || OCP.param2 == 'I') && OCP.param3 == 'D')
		{
			result = (short)hex_to_int(0x00, 0x00, map->arena[(POS + 3) % MEM_SIZE], map->arena[(POS + 4) % MEM_SIZE]);
			result += (short)hex_to_int(0x00, 0x00, map->arena[(POS + 5) % MEM_SIZE], map->arena[(POS + 6) % MEM_SIZE]);
			proc->pc = proc->pc + 7;
		}
		else if ((OCP.param2 == 'D' || OCP.param2 == 'I') && OCP.param3 == 'R')
		{
			if (!is_register((int)map->arena[(POS + 5) % MEM_SIZE]))
			{
				fail_func(proc, 6, 0);
				return ;
			}
			result = (short)hex_to_int(0x00, 0x00, map->arena[(POS + 3) % MEM_SIZE], map->arena[(POS + 4) % MEM_SIZE]);
			result += proc->reg[(int)map->arena[(POS + 5) % MEM_SIZE] - 1];
			proc->pc = proc->pc + 6;
		}
		else
		{
			proc->pc = proc->pc + 5;
			return ;
		}
		place_in_arena(map, (POS + result) % MEM_SIZE, proc->reg[REG_NBR - 1]);
	}
}
