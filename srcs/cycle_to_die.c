/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:34:11 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/09 16:36:39 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cycle_to_die(t_map *map)
{
	if (map->cycle == map->next_ctd)
	{
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
