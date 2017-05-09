/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:34:11 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/09 17:06:05 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_last_live(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nb_player)
	{
		if (player[i].last_live < map->next_ctd - map->cycle_to_die)
			kill_player(map, i);
		i++;
	}
}

void	cycle_to_die(t_map *map)
{
	if (map->cycle == map->next_ctd)
	{
		check_last_live(map);
		if (map->nb_live >= NBR_LIVE - 1 || map->check == MAX_CHECKS - 1)
		{
			printf("Nb live = %d\n", map->nb_live);
			map->check = 0;
			map->nb_live = 0;
			map->cycle_to_die -= CYCLE_DELTA;
			printf("Nb cycle = %d\nNb cycle_to_die = %d\n\n", map->cycle, map->cycle_to_die);
		}
		else
		{
			map->check++;
			map->nb_live = 0;
		}
		map->next_ctd += map->cycle_to_die;
	}
}
