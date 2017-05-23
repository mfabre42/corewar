/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:34:11 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/23 16:01:36 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_last_live(t_map *map)
{
	int	i;
	t_process *tmp;
	t_process *tmp2;

	i = 0;
	while (i < map->nb_player)
	{
	//	printf("last_live: %d, next_ctd: %d, cycle_to_die: %d, cycle: %d\n", map->player[i].last_live, map->next_ctd, map->cycle_to_die, map->cycle);
		if (map->player[i].last_live < map->next_ctd - map->cycle_to_die)
		{
			// printf("last_live: %d, next_ctd: %d, cycle_to_die: %d, player: %d\n", map->player[i].last_live, map->next_ctd, map->cycle_to_die, i);
			kill_player(map, i);
		}
		else
		{
			tmp = map->player[i].process;
			while (tmp != NULL)
			{
				tmp2 = tmp->next;
				if (tmp->last_live < map->next_ctd - map->cycle_to_die)
					kill_process(map, i, tmp);
				tmp = tmp2;
			}
		}
		i++;
	}
}

void	cycle_to_die(t_map *map)
{
	if (map->cycle == map->next_ctd)
	{
		check_last_live(map);
		if (map->nb_live >= NBR_LIVE || map->check == MAX_CHECKS - 1)
		{
			// printf("Nb live = %d\n", map->nb_live);
			map->check = 0;
			map->nb_live = 0;
			map->cycle_to_die -= CYCLE_DELTA;
			// printf("Nb cycle = %d\nNb cycle_to_die = %d\n\n", map->cycle, map->cycle_to_die);
		}
		else
		{
			map->check++;
			map->nb_live = 0;
		}
		map->next_ctd += map->cycle_to_die;
	}
}
