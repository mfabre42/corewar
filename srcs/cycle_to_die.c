/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:34:11 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/09 16:07:23 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cycle_to_die(t_map *map)
{
	if (map->cycle == map->next_ctd)
	{
		if (map->nb_live >= NBR_LIVE || map->check == 10)
		{
			map->check = 0;
			map->nb_live = 0;
			map->cycle_to_die -= CYCLE_DELTA;
		}
		else
		{
			map->check++;
		}
		map->next_ctd += map->cycle_to_die;
	}
}
