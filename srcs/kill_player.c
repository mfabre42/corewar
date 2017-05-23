/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:13:28 by anonymou          #+#    #+#             */
/*   Updated: 2017/05/23 20:55:51 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_player(t_map *map, int n_player)
{
//	printf("KILL player: %d", n_player);
	if (map->player[n_player].process != NULL)
		ft_lstdel(&map->player[n_player].process);
	map->player[n_player].in_life = 0;
}

void	kill_process(t_map *map, int i, t_process *proc)
{
	t_process *tmp1;
	t_process *tmp2;
	t_process *tmp3;

	tmp1 = map->player[i].process;
	// printf("Kill player: %d, proc_id: %d, at cycle: %d, tmp1: %p, proc: %p, tmp2: %p, tmp3: %p, last_live: %d\n", i, proc->id, map->cycle, tmp1, proc, tmp2, tmp3, proc->last_live);
	if (tmp1 == proc)
	{
		tmp2 = tmp1->next;
		ft_lstdelone(&tmp1);
		map->player[i].process = tmp2;
	}
	else
	{
		while (tmp1 != NULL && tmp1 != proc)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		if (tmp1 != NULL)
		{
			tmp3 = tmp1->next;
			ft_lstdelone(&tmp1);
			// printf("Kill player: tmp1: %p, proc: %p, tmp2: %p, tmp3: %p\n", tmp1, proc, tmp2, tmp3);
			tmp2->next = tmp3;
			// printf("Kill player: tmp1: %p, proc: %p, tmp2: %p, tmp3: %p\n", tmp1, proc, tmp2, tmp3);
		}
	}
}
