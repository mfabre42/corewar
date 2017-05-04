/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:34:48 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/04 18:09:40 by acoupleu         ###   ########.fr       */
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
		proc->cycle = 25;
		proc->do_funk = 0;
	}
	else
	{
		proc->do_funk = 1;
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[pos + 1]);
		if (ocp.param1 == 'R' && ocp.param2 == 'R')
		{
			if (!is_register((int)map->arena[pos + 2])
			|| !is_register((int)map->arena[pos + 3])
			|| !is_register((int)map->arena[pos + 4]))
			{
				printf("crash process a gerer"); //LOL
				exit(0);
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
				printf("crash process a gerer"); //LOL
				exit(0);
			}
			result = proc->reg[(int)map->arena[pos + 2] - 1];
			result += hex_to_int(0x00, 0x00, map->arena[pos + 3], map->arena[pos + 4]);
			proc->reg[(int)map->arena[pos + 5] - 1] = read_in_arena(map, pos + (result % IDX_MOD));
			proc->pc = proc->pc + 6;
		}
		else if (ocp.param1 == 'D' || ocp.param1 == 'I') && ocp.param2 == 'R')
		{
			if (!is_register((int)map->arena[pos + 4])
			|| !is_register((int)map->arena[pos + 5]))
			{
				printf("crash process a gerer"); //LOL
				exit(0);
			}
			result = hex_to_int(0x00, 0x00, map->arena[pos + 2], map->arena[pos + 3]);
			result += proc->reg[(int)map->arena[pos + 4] - 1];
			proc->reg[(int)map->arena[pos + 5] - 1] = read_in_arena(map, pos + (result % IDX_MOD));
			proc->pc = proc->pc + 6;
		}
		else if (ocp.param1 == 'D' || ocp.param1 == 'I') && ocp.param2 == 'D')
		{
			if (!is_register((int)map->arena[pos + 6]))
			{
				printf("crash process a gerer"); //LOL
				exit(0);
			}
			result = hex_to_int(0x00, 0x00, map->arena[pos + 2], map->arena[pos + 3]);
			result += hex_to_int(0x00, 0x00, map->arena[pos + 4], map->arena[pos + 5]);
			proc->reg[(int)map->arena[pos + 6] - 1] = read_in_arena(map, pos + (result % IDX_MOD));
			proc->pc = proc->pc + 7;
		}
}
