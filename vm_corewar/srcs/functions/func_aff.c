/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:43:55 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/31 18:54:27 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff_char(t_map *map, t_process *proc)
{
	int		pos;
	t_ocp	ocp;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 0, 16, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)ARENA[(pos + 1) % MEM_SIZE]);
		if (ocp.param1 == 'R')
		{
			if (!is_reg((int)ARENA[(pos + 2) % MEM_SIZE], proc, 3))
				return ;
			if (map->mute_aff == 1)
				ft_putchar((proc->reg[(int)ARENA[(pos + 2) % MEM_SIZE] - 1])
					% 256);
		}
		proc->pc = proc->pc + 3;
	}
}
