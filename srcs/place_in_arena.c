/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_in_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 23:07:14 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/23 22:27:00 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			place_in_arena(t_map *map, int dest, int nbr)
{
	t_convert conv;

	dest = dest + 65536;
	conv.c_int = nbr;
	map->arena[dest % MEM_SIZE] = conv.c_char[3];
	map->arena[(dest + 1) % MEM_SIZE] = conv.c_char[2];
	map->arena[(dest + 2) % MEM_SIZE] = conv.c_char[1];
	map->arena[(dest + 3) % MEM_SIZE] = conv.c_char[0];
}

unsigned int	read_in_arena(t_map *map, int adress)
{
	t_convert conv;

	conv.c_char[3] = map->arena[adress];
	conv.c_char[2] = map->arena[adress + 1];
	conv.c_char[1] = map->arena[adress + 2];
	conv.c_char[0] = map->arena[adress + 3];
	return (conv.c_int);
}
