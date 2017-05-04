/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:42:39 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/04 20:08:43 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	addition(t_map *map, t_process *proc)
{
	int		pos;

	if (proc->do_funk == 1)
	{
		proc->cycle = 9;
		proc->do_funk = 0;
	}
	else
	{
		proc->do_funk = 1;
		pos = proc->start + proc->pc;
		if (!is_register((int)map->arena[pos + 1]) ||
			!is_register((int)map->arena[pos + 2]) ||
			!is_register((int)map->arena[pos + 3]))
			{
				printf("crash process a gerer"); //LOL
				exit(0);
			}
		else
		{
			proc->reg[map->arena[pos + 3] - 1] =
			proc->reg[map->arena[pos + 2] - 1] +
			proc->reg[map->arena[pos + 1] - 1];
			if (proc->reg[map->arena[pos + 3] - 1] == 0x00)
				proc->carry = 0;
			else
				proc->carry = 1;
			proc->pc = proc->pc + 4;
		}
	}
}
