/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:57:24 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/04 23:35:00 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	func_xor(t_map *map, t_process *proc)
{
	int		pos;
	t_ocp	ocp;
	int		pc;
	int		param1;

	if (proc->do_funk == 1)
	{
		proc->cycle = 5;
		proc->do_funk = 0;
	}
	else
	{
		proc->do_funk = 1;
		pc = 2;
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[pos + 1]);
		if (ocp.param1 == 'R')
		{
//			if (!is_register(()))
			param1 = proc->reg[(int)map->arena[pos + pc] - 1];
			pc += 1;
		}
		else if (ocp.param1 == 'I')
		{
			param1 = hex_to_int(0x00, 0x00, map->arena[pos + 2], map->arena[pos + 3]);
			pc += 2;
		}
		else if (ocp.param1 == 'D')
		{
			param1 = hex_to_int(map->arena[pos + 2], map->arena[pos + 3],
				map->arena[pos + 4], map->arena[pos + 5]);
			pc += 4;
		}
		if (ocp.param2 == 'R')
		{
//			if (!is_register(()))
			param1 = param1 ^ proc->reg[(int)map->arena[pos + pc] - 1];
			pc += 1;
		}
		else if (ocp.param2 == 'I')
		{
			param1 = param1 ^ hex_to_int(0x00, 0x00, map->arena[pos + pc], map->arena[pos + pc + 1]);
			pc += 2;
		}
		else if (ocp.param2 == 'D')
		{
			param1 = param1 ^ hex_to_int(map->arena[pos + pc], map->arena[pos + pc + 1],
				map->arena[pos + pc + 2], map->arena[pos + pc + 3]);
			pc += 4;
		}
		//			if (!is_register(()))
		proc->reg[(int)map->arena[pos + pc] - 1] = param1;
		proc->pc += pc + 1;
	}
}
