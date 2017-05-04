/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:26:28 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/03 19:36:22 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	jump_if_zero(t_map *map, t_process *proc)
{
	int	pos;
	int	result;

	if (proc->do_funk == 1)
	{
		proc->cycle = 20;
		proc->do_funk = 0;
	}
	else
	{
		proc->do_funk = 1;
		pos = proc->start + proc->pc;
		if (proc->carry == 1)
		{
			result = hex_to_int(0x00, 0x00, map->arena[pos + 1],
				map->arena[pos + 2]);
			proc->pc = (proc->pc + result) % IDX_MOD;
		}
	}
}
