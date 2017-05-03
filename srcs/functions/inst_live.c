/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:03:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/03 17:58:20 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_map map, t_process *proc, int n_player)
{
	int player;

	pos = proc->start + proc->pc;
	player = hex_to_int(map->arena[pos + 1], map->arena[pos + 2],
		map->arena[pos + 3], map->arena[pos + 4]);
	if (player >= 1 && player <= map->nb_player)
	{
		printf("Le joueur %s(%d), a ete rapporter comme etant en vie\n"
		, map->player[player], player);
		map->player[player].last_live = map->cycle;
	}
}
