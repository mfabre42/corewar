/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:34:09 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/04 23:44:04 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	direct_store(t_map *map, t_process *proc)
{
	int		reg_nbr;
	int		pos;
	int		result;
	t_ocp	ocp;


	if (proc->do_funk == 1)
	{
		proc->cycle = 4;
		proc->do_funk = 0;
	}
	else
	{
		proc->do_funk = 1;
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[pos + 1]);
		reg_nbr = (int)map->arena[pos + 2];
		if (!is_register(reg_nbr))
		{
			printf("crash process a gerer st"); //LOL
			exit(0);
		}
		if (ocp.param2 == 'R')
		{
			if (!is_register(hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 3])))
			{
				printf("crash process a gerer st"); //LOL
				exit(0);
			}
			proc->reg[(int)map->arena[pos + 3] - 1] =  proc->reg[reg_nbr - 1];
			proc->pc = proc->pc + 4;
		}
		else
		{
			result = hex_to_int(0x00, 0x00, map->arena[pos + 3], map->arena[pos + 4]);
			proc->pc = proc->pc + 5;
		}
		place_in_arena(map, pos + (result % IDX_MOD), proc->reg[reg_nbr - 1]);
	}
}
