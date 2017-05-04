/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:51:41 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/04 23:35:25 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lfork(t_map *map, t_process *proc, int player)
{
	int		pos;
	int		dest;

	if (proc->do_funk == 1)
	{
		proc->cycle = 999;
		proc->do_funk = 0;
	}
	else
	{
		proc->do_funk = 1;
		pos = proc->start + proc->pc;
		dest = pos + (hex_to_int(0x00, 0x00, map->arena[pos + 1],
			map->arena[pos + 2]));
		cp_process(map, proc, player, dest);
		proc->pc = proc->pc + 3;
	}
}
