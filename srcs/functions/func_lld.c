/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_lld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:39:11 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/04 20:17:43 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ldirect_load(t_map *map, t_process *proc)
{
	int		pos;
	t_ocp	ocp;
	int		reg_nbr;

	if (proc->do_funk == 1)
	{
		proc->cycle = 9;
		proc->do_funk = 0;
	}
	else
	{
		proc->do_funk = 1;
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map_arena[pos + 1]);
		if (ocp.param1 == 'D')
		{
			if (!is_register((int)map->arena[pos + 6]))
			{
				printf("crash");
				exit(0);
			}
			reg_nbr = (int)map->arena[pos + 6];
			proc->reg[reg_nbr - 1] = map->arena[pos + hex_to_int(map->arena[pos + 2],
				map->arena[pos + 3], map->arena[pos + 4], map->arena[pos + 5])];
				proc->pc = proc->pc + 7;
		//	if (proc->reg[reg_nbr - 1] == 0)
		//		proc->carry
		}
		else if (ocp.param1 == 'I')
		{
			if (!is_register((int)map->arena[pos + 4]))
			{
				printf("crash");
				exit(0);
			}
			reg_nbr = (int)map->arena[pos + 4];
			proc->reg[reg_nbr - 1] = map->arena[pos + hex_to_int(0x00,
				0x00, map->arena[pos + 2], map->arena[pos + 3])];
			proc->pc = proc->pc + 5;
		}
	}
}
