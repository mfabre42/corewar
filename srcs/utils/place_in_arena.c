/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_in_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 23:07:14 by acoupleu          #+#    #+#             */
/*   Updated: 2017/04/27 23:11:37 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	place_in_arena(t_map *map, int dest, int nbr)
{
	t_convert conv;

	t_convert.c_int = nbr;
	map->arena[dest] = t_convert.c_char[0];
	map->arena[dest + 1] = t_convert.c_char[1];
	map->arena[dest + 2] = t_convert.c_char[2];
	map->arena[dest + 3] = t_convert.c_char[3];
}
