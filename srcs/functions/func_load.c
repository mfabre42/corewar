/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:31:28 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/10 15:40:12 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	direct_load(t_map *map, t_process *proc)
{
	int		pos;
	t_ocp	ocp;
	int		reg_nbr;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 3, 2, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[pos + 1]);
		if (ocp.param1 == 'D')
		{
			if (!is_register((int)map->arena[pos + 6]))
			{
				fail_func(proc, 7, 1);
				return ;
			}
			reg_nbr = (int)map->arena[pos + 6];
			proc->reg[reg_nbr - 1] = map->arena[pos + (hex_to_int(map->arena[pos + 2],
				map->arena[pos + 3], map->arena[pos + 4], map->arena[pos + 5]) % IDX_MOD)];
				proc->pc = proc->pc + 7;
		}
		else if (ocp.param1 == 'I')
		{
			if (!is_register((int)map->arena[pos + 4]))
			{
				fail_func(proc, 5, 1);
				return ;
			}
			reg_nbr = (int)map->arena[pos + 4];
			proc->reg[reg_nbr - 1] = map->arena[pos + (hex_to_int(0x00,
				0x00, map->arena[pos + 2], map->arena[pos + 3]) % IDX_MOD)];
			proc->pc = proc->pc + 5;
		}
		proc->carry = 1;
	}
}
