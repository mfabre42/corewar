/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:03:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/09 16:53:43 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_map *map, t_process *proc)
{
	int player;
	int pos;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 9, 1, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		player = hex_to_int(map->arena[pos + 1], map->arena[pos + 2],
			map->arena[pos + 3], map->arena[pos + 4]);
		if (player >= 1 && player <= map->nb_player)
		{
			map->nb_live++;
			// printf("Le joueur %s(%d), a ete rapporter comme etant en vie\n"
			// , map->player[player].name, player);
			map->player[player].last_live = map->cycle;
		}
		proc->pc = proc->pc + 5;
	}
}
