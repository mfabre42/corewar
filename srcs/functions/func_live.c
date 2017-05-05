/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:03:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/05 16:57:24 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_map *map, t_process *proc)
{
	int player;
	int pos;

	printf("\n\nMonsieur essaye de faire un live\n\n");
	if (proc->do_funk == 1)
	{
		proc->cycle = 9;
		proc->do_funk = 0;
	}
	else
	{
		proc->do_funk = 1;
		pos = proc->start + proc->pc;
		player = hex_to_int(map->arena[pos + 1], map->arena[pos + 2],
			map->arena[pos + 3], map->arena[pos + 4]);
		if (player >= 1 && player <= map->nb_player)
		{
			printf("Le joueur %s(%d), a ete rapporter comme etant en vie\n"
			, map->player[player].name, player);
			map->player[player].last_live = map->cycle;
		}
		proc->pc = proc->pc + 5;
	}
}
