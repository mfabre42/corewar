/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:26:28 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/23 01:37:23 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	jump_if_zero(t_map *map, t_process *proc)
{
	int	pos;
	int	result;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 18, 9, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		// printf("Tu jump pas parce que tu n'as pas de jambe qui te carry %d au cycle: %d pos:%d\n", proc->carry, map->cycle, pos);
		if (proc->carry == 1)
		{
			result = (short)hex_to_int(0x00, 0x00, map->arena[(pos + 1) % MEM_SIZE],
				map->arena[(pos + 2) % MEM_SIZE]);
			proc->pc = proc->pc + result % IDX_MOD;
			// printf("Maintenant, tu %d jump au numero: %d, pc: %d, start: %d au cycle %d\n", proc->id, proc->pc + proc->start, proc->pc, proc->start, map->cycle);
		}
		else
			proc->pc += 3;
	}
}
