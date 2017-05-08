/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:34:48 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/08 14:01:53 by aleveque         ###   ########.fr       */
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
		do_funk(proc, 24, 10, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[pos + 1]);
		if (ocp.param1 == 'R' && ocp.param2 == 'R')
		{
			if (!is_register((int)map->arena[pos + 2])
			|| !is_register((int)map->arena[pos + 3])
			|| !is_register((int)map->arena[pos + 4]))
			{
				fail_func(proc, 5, 0);
				return ;
			}
			result = proc->reg[(int)map->arena[pos + 2] - 1];
			result += proc->reg[(int)map->arena[pos + 3] - 1];
			proc->reg[(int)map->arena[pos + 4] - 1] = read_in_arena(map, pos + (result % IDX_MOD));
			proc->pc = proc->pc + 5;
		}
		else if (ocp.param1 == 'R' && ocp.param2 == 'D')
		{
			if (!is_register((int)map->arena[pos + 2])
			|| !is_register((int)map->arena[pos + 5]))
			{
				fail_func(proc, 6, 0);
				return ;
			}
			result = proc->reg[(int)map->arena[pos + 2] - 1];
			result += hex_to_int(0x00, 0x00, map->arena[pos + 3], map->arena[pos + 4]);
			proc->reg[(int)map->arena[pos + 5] - 1] = read_in_arena(map, pos + (result % IDX_MOD));
			proc->pc = proc->pc + 6;
		}
		else if ((ocp.param1 == 'D' || ocp.param1 == 'I') && ocp.param2 == 'R')
		{
			if (!is_register((int)map->arena[pos + 4])
			|| !is_register((int)map->arena[pos + 5]))
			{
				fail_func(proc, 6, 0);
				return ;
			}
			result = hex_to_int(0x00, 0x00, map->arena[pos + 2], map->arena[pos + 3]);
			result += proc->reg[(int)map->arena[pos + 4] - 1];
			proc->reg[(int)map->arena[pos + 5] - 1] = read_in_arena(map, pos + (result % IDX_MOD));
			proc->pc = proc->pc + 6;
		}
		else if ((ocp.param1 == 'D' || ocp.param1 == 'I') && ocp.param2 == 'D')
		{
			if (!is_register((int)map->arena[pos + 6]))
			{
				fail_func(proc, 7, 0);
				return ;
			}
			result = hex_to_int(0x00, 0x00, map->arena[pos + 2], map->arena[pos + 3]);
			result += hex_to_int(0x00, 0x00, map->arena[pos + 4], map->arena[pos + 5]);
			proc->reg[(int)map->arena[pos + 6] - 1] = read_in_arena(map, pos + (result % IDX_MOD));
			proc->pc = proc->pc + 7;
		}
	}
}
