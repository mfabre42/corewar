/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:15:10 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/02 18:59:30 by mafabre          ###   ########.fr       */
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
		proc->cycle = 25;
		proc->do_funk = 0;
	}
	else
	{
		printf("ICI\n");
		proc->do_funk = 1;
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[pos + 1]);
		reg_nbr = (int)map->arena[pos + 2];
		if (ocp.param2 == 'R')
		{
			if (!is_register(hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 3])))
			{
				printf("crash process a gerer"); //LOL
				exit(0);
			}
			result = proc->reg[hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 3]) - 1];
			result += hex_to_int(0x00, 0x00, map->arena[pos + 4],
				map->arena[pos + 5]);
			proc->pc = proc->pc + 6;
		}
		else
		{
			result = hex_to_int(0x00, 0x00, map->arena[pos + 3], map->arena[pos + 4]);
			result += hex_to_int(0x00, 0x00, map->arena[pos + 5], map->arena[pos + 6]);
			proc->pc = proc->pc + 7;
		}
		place_in_arena(map, pos + (result % IDX_MOD), proc->reg[reg_nbr - 1]);
	}
}
