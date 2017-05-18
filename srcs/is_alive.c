/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 21:04:01 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/18 16:49:53 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_alive(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->nb_player)
	{
		if (map->player[i].in_life == 1)
			return (1);
		i++;
	}
	return (0);
}

int		check_last_survivor(t_map *map)
{
	int		i;
	int		warrior;

	i = 0;
	warrior = 0;
	while (i < map->nb_player)
	{
		if (map->player[i].last_live > map->player[warrior].last_live)
		{
			warrior = i;
			// printf("last live player[%d]%s = %d\n", i, map->player[i].name, map->player[i].last_live);
		}
		i++;
	}
	return (warrior);
}
