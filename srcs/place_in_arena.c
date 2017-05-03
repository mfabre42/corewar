/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_in_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 23:07:14 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/02 17:48:10 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	place_in_arena(t_map *map, int dest, int nbr)
{
	t_convert conv;

	conv.c_int = nbr;
	map->arena[dest] = conv.c_char[3];
	map->arena[dest + 1] = conv.c_char[2];
	map->arena[dest + 2] = conv.c_char[1];
	map->arena[dest + 3] = conv.c_char[0];
}
