/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:03:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/16 20:29:53 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_map *map, t_process *proc)
{
	int player;
	int pos;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 8, 1, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		player = hex_to_int(map->arena[(pos + 1) % MEM_SIZE], map->arena[(pos + 2) % MEM_SIZE],
			map->arena[(pos + 3) % MEM_SIZE], map->arena[(pos + 4) % MEM_SIZE]);
		if (player >= 1 && player <= map->nb_player)
		{
			map->nb_live++;
			printf("Le joueur (%d), a ete rapporter comme etant en vie,cycle:%d\n"
			,  player, map->cycle);
			map->player[player].last_live = map->cycle;
		}
		proc->pc = proc->pc + 5;
	}
}
