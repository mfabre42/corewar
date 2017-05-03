/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:15:10 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/03 16:42:42 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	indirect_store(t_map *map, t_process *proc)
{
	int		reg_nbr;
	int		pos;
	int		result;
	t_ocp	ocp;

	pos = proc->start + proc->pc;
	ocp = ocp_master((int)map->arena[pos + 1]);
	reg_nbr = (int)map->arena[pos + 2];
	if (ocp.param2 == 'R' && ocp.param3 == 'D')
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
	else if (ocp.param2 == 'R' && ocp.param3 == 'R')
	{
		if (!is_register(hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 3]))
			|| !is_register(hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 4])))
		{
			printf("crash process a gerer"); //LOL
			exit(0);
		}
		result = proc->reg[hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 3]) - 1];
		result += proc->reg[hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 4]) - 1];
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
		if (!is_register(hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 5])))
		{
			printf("crash process a gerer"); //LOL
			exit(0);
		}
		result = hex_to_int(0x00, 0x00, map->arena[pos + 3], map->arena[pos + 4]);
		result += proc->reg[hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 5]) - 1];
		proc->pc = proc->pc + 6;
	}
	proc->cycle = 25;
	place_in_arena(map, pos + (result % IDX_MOD), proc->reg[reg_nbr - 1]);
}
