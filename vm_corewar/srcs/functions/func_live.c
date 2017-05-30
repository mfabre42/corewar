/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:03:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/23 23:38:39 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_map *map, t_process *proc)
{
	int player;
	int pos;

	if (proc->do_funk == 1)
		do_funk(proc, 8, 1, 0);
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		player = hex_to_int(ARENA[(pos + 1) % MEM_SIZE],
		ARENA[(pos + 2) % MEM_SIZE],
			ARENA[(pos + 3) % MEM_SIZE], ARENA[(pos + 4) % MEM_SIZE]);
		if (player >= 1 && player <= map->nb_player)
		{
			if (map->mute == 0)
				ft_printf(
					"Le joueur %s(%d), a ete rapporter comme etant en vie\n",
					map->player[player - 1].name, player);
			map->player[player - 1].last_live = map->cycle;
		}
		proc->last_live = map->cycle;
		map->nb_live++;
		proc->pc = proc->pc + 5;
	}
}
