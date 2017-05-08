/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:15:10 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/08 14:19:27 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	indirect_store(t_map *map, t_process *proc)
{
	int		reg_nbr;
	int		pos;
	int		result;
	t_ocp	ocp;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 24, 11, 1);
		proc->cycle = 24;
		proc->do_funk = 0;
	}
	else
	{
		// printf("pc : %d\n", proc->pc);
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[pos + 1]);
		if (!is_register((int)map->arena[pos + 2]))
		{
			fail_func(proc, 5, 0);
			return ;
		}
		reg_nbr = (int)map->arena[pos + 2];
		if (ocp.param2 == 'R' && ocp.param3 == 'D')
		{
			if (!is_register((int)map->arena[pos + 3]))
			{
				fail_func(proc, 6, 0);
				return ;
			}
			result = proc->reg[(int)map->arena[pos + 3] - 1];
			result += hex_to_int(0x00, 0x00, map->arena[pos + 4],
				map->arena[pos + 5]);
			proc->pc = proc->pc + 6;
		}
		else if (ocp.param2 == 'R' && ocp.param3 == 'R')
		{
			if (!is_register((int)map->arena[pos + 3])
				|| !is_register((int)map->arena[pos + 4]))
			{
				fail_func(proc, 5, 0);
				return ;
			}
			result = proc->reg[(int)map->arena[pos + 3] - 1];
			result += proc->reg[(int)map->arena[pos + 4] - 1];
			proc->pc = proc->pc + 5;
		}
		else if ((ocp.param2 == 'D' || ocp.param2 == 'I') && ocp.param3 == 'D')
		{

			result = hex_to_int(0x00, 0x00, map->arena[pos + 3], map->arena[pos + 4]);
			result += hex_to_int(0x00, 0x00, map->arena[pos + 5], map->arena[pos + 6]);
			proc->pc = proc->pc + 7;
		}
		else if ((ocp.param2 == 'D' || ocp.param2 == 'I') && ocp.param3 == 'R')
		{
			if (!is_register((int)map->arena[pos + 5]))
			{
				fail_func(proc, 6, 0);
				return ;
			}
			result = hex_to_int(0x00, 0x00, map->arena[pos + 3], map->arena[pos + 4]);
			result += proc->reg[(int)map->arena[pos + 5] - 1];
			proc->pc = proc->pc + 6;
		}
		place_in_arena(map, pos + (result % IDX_MOD), proc->reg[reg_nbr - 1]);
	}
	// printf("pc : %d\n", proc->pc);
}
