/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:26:28 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/08 14:28:01 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	jump_if_zero(t_map *map, t_process *proc)
{
	int	pos;
	int	result;

//	printf("Je suis un kangourou\n");
	if (proc->do_funk == 1)
	{
		do_funk(proc, 19, 9, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		if (proc->carry == 1)
		{
			result = hex_to_int(0x00, 0x00, map->arena[pos + 1],
				map->arena[pos + 2]);
			proc->pc = (proc->pc + result) % IDX_MOD;
		}
	}
}
