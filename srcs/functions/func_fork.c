/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:19:37 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/15 21:10:24 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	forkniquer(t_map *map, t_process *proc, int player)
{
	int		pos;
	int		dest;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 798, 12, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		dest = (pos + (short)(hex_to_int(0x00, 0x00, map->arena[(pos + 1) % MEM_SIZE],
			map->arena[(pos + 2) % MEM_SIZE]))) % IDX_MOD;
		printf("fork at :%d, to %d\n", map->cycle, dest);
		cp_process(map, proc, player, dest);
		proc->pc = proc->pc + 3;
	}
}
