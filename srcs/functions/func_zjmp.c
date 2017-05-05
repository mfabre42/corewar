/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:26:28 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/05 17:52:08 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	jump_if_zero(t_map *map, t_process *proc)
{
	int	pos;
	int	result;

	printf("Je suis un kangourou\n");
	if (proc->do_funk == 1)
	{
		proc->cycle = 19;
		proc->do_funk = 0;
	}
	else
	{
		proc->do_funk = 1;
		pos = proc->start + proc->pc;
		if (proc->carry == 0)///OMG LE CARRY DOIT ETRE A 1
		{
			result = hex_to_int(0x00, 0x00, map->arena[pos + 1],
				map->arena[pos + 2]);
			proc->pc = (proc->pc + result) % IDX_MOD;
		}
	}
}
