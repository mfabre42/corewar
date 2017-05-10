/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:03:03 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/10 15:39:58 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	substraction(t_map *map, t_process *proc)
{
	int		pos;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 8, 5, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		if (!is_register((int)map->arena[pos + 1]) ||
			!is_register((int)map->arena[pos + 2]) ||
			!is_register((int)map->arena[pos + 3]))
			{
				fail_func(proc, 4, 1);
				return ;
			}
		else
		{
			proc->reg[map->arena[pos + 3] - 1] =
			proc->reg[map->arena[pos + 2] - 1] -
			proc->reg[map->arena[pos + 1] - 1];
			proc->carry = 1;
			proc->pc = proc->pc + 4;
		}
	}
}
