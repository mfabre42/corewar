/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:42:39 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/23 20:40:57 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	addition(t_map *map, t_process *proc)
{
	int		pos;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 8, 4, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		if (!is_register((int)map->arena[(pos + 2) % MEM_SIZE]) ||
			!is_register((int)map->arena[(pos + 3) % MEM_SIZE]) ||
			!is_register((int)map->arena[(pos + 4) % MEM_SIZE]))
		{
			fail_func(proc, 5, 1);
			return ;
		}
		proc->reg[map->arena[(pos + 4) % MEM_SIZE] - 1] =
		proc->reg[map->arena[(pos + 2) % MEM_SIZE] - 1] +
		proc->reg[map->arena[(pos + 3) % MEM_SIZE] - 1];
		// printf("registre %d vaut %d\n",
		// map->arena[(pos + 3) % MEM_SIZE],
		// proc->reg[map->arena[(pos + 3) % MEM_SIZE] - 1]);
		proc->carry = !proc->reg[map->arena[(pos + 4) % MEM_SIZE] - 1];
		proc->pc = proc->pc + 5;
		// printf("proc->pc = %d\n", proc->pc + proc->start);
	}
}
