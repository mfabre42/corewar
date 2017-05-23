/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:43:55 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/24 00:44:09 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff_char(t_map *map, t_process *proc)
{
	int		pos;
	int		result;
	t_ocp	ocp;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 0, 16, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		// if ((pos + 1) % MEM_SIZE < 0)
		// printf("map->arena[(pos + 1) %% MEM_SIZE] = %02x, pos : %d, cycle : %d, start: %d, pc: %d\n", map->arena[(pos + 1) % MEM_SIZE], (pos + 1) % MEM_SIZE, map->cycle, proc->start, proc->pc);
		ocp = ocp_master((int)map->arena[(pos + 1) % MEM_SIZE]);
		if (ocp.param1 == 'R')
		{
			if (!is_reg((int)map->arena[(pos + 2) % MEM_SIZE], proc, 3))
				return ;
			ft_putchar((proc->reg[(int)map->arena[(pos + 2) % MEM_SIZE] - 1])
			% 256);
		}
		proc->pc = proc->pc + 3;
	}
}
