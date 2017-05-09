/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_alive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 21:04:01 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/09 21:08:27 by acoupleu         ###   ########.fr       */
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
