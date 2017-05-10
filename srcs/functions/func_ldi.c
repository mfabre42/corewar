/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:34:48 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/10 18:19:23 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	indirect_load(t_map *map, t_process *proc)
{
	int		pos;
	int		result;
	t_ocp	ocp;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 23, 10, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[(pos + 1) % MEM_SIZE]);
		if (ocp.param1 == 'R' && ocp.param2 == 'R')
		{
			if (!is_register((int)map->arena[(pos + 2) % MEM_SIZE])
			|| !is_register((int)map->arena[(pos + 3) % MEM_SIZE])
			|| !is_register((int)map->arena[(pos + 4) % MEM_SIZE]))
			{
				fail_func(proc, 5, 0);
				return ;
			}
			result = proc->reg[(int)map->arena[(pos + 2) % MEM_SIZE] - 1];
			result += proc->reg[(int)map->arena[(pos + 3) % MEM_SIZE] - 1];
			proc->reg[(int)map->arena[(pos + 4) % MEM_SIZE] - 1] = read_in_arena(map, (pos + (result % IDX_MOD)) % MEM_SIZE);
			proc->pc = proc->pc + 5;
		}
		else if (ocp.param1 == 'R' && ocp.param2 == 'D')
		{
			if (!is_register((int)map->arena[(pos + 2) % MEM_SIZE])
			|| !is_register((int)map->arena[(pos + 5) % MEM_SIZE]))
			{
				fail_func(proc, 6, 0);
				return ;
			}
			result = proc->reg[(int)map->arena[(pos + 2) % MEM_SIZE] - 1];
			result += hex_to_int(0x00, 0x00, map->arena[(pos + 3) % MEM_SIZE], map->arena[(pos + 4) % MEM_SIZE]);
			proc->reg[(int)map->arena[(pos + 5) % MEM_SIZE] - 1] = read_in_arena(map, (pos + (result % IDX_MOD)) % MEM_SIZE);
			proc->pc = proc->pc + 6;
		}
		else if ((ocp.param1 == 'D' || ocp.param1 == 'I') && ocp.param2 == 'R')
		{
			if (!is_register((int)map->arena[(pos + 4) % MEM_SIZE])
			|| !is_register((int)map->arena[(pos + 5) % MEM_SIZE]))
			{
				fail_func(proc, 6, 0);
				return ;
			}
			result = hex_to_int(0x00, 0x00, map->arena[(pos + 2) % MEM_SIZE], map->arena[(pos + 3) % MEM_SIZE]);
			result += proc->reg[(int)map->arena[(pos + 4) % MEM_SIZE] - 1];
			proc->reg[(int)map->arena[(pos + 5) % MEM_SIZE] - 1] = read_in_arena(map, (pos + (result % IDX_MOD)) % MEM_SIZE);
			proc->pc = proc->pc + 6;
		}
		else if ((ocp.param1 == 'D' || ocp.param1 == 'I') && ocp.param2 == 'D')
		{
			if (!is_register((int)map->arena[(pos + 6) % MEM_SIZE]))
			{
				fail_func(proc, 7, 0);
				return ;
			}
			result = hex_to_int(0x00, 0x00, map->arena[(pos + 2) % MEM_SIZE], map->arena[(pos + 3) % MEM_SIZE]);
			result += hex_to_int(0x00, 0x00, map->arena[(pos + 4) % MEM_SIZE], map->arena[(pos + 5) % MEM_SIZE]);
			proc->reg[(int)map->arena[(pos + 6) % MEM_SIZE] - 1] = read_in_arena(map, (pos + (result % IDX_MOD)) % MEM_SIZE);
			proc->pc = proc->pc + 7;
		}
	}
}
