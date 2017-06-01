/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_in_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 23:07:14 by acoupleu          #+#    #+#             */
/*   Updated: 2017/06/01 18:38:05 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			place_in_arena(t_map *map, int dest, int nbr, int player)
{
	t_convert conv;

	dest = dest + 65536;
	conv.c_int = nbr;
	ARENA[dest % MEM_SIZE] = conv.c_char[3];
	ARENA[(dest + 1) % MEM_SIZE] = conv.c_char[2];
	ARENA[(dest + 2) % MEM_SIZE] = conv.c_char[1];
	ARENA[(dest + 3) % MEM_SIZE] = conv.c_char[0];
	ARENA_CLAIM[dest % MEM_SIZE] = player;
	ARENA_CLAIM[(dest + 1) % MEM_SIZE] = player;
	ARENA_CLAIM[(dest + 2) % MEM_SIZE] = player;
	ARENA_CLAIM[(dest + 3) % MEM_SIZE] = player;
}

unsigned int	read_in_arena(t_map *map, int adress)
{
	t_convert conv;

	conv.c_char[3] = ARENA[adress % MEM_SIZE];
	conv.c_char[2] = ARENA[adress + 1 % MEM_SIZE];
	conv.c_char[1] = ARENA[adress + 2 % MEM_SIZE];
	conv.c_char[0] = ARENA[adress + 3 % MEM_SIZE];
	return (conv.c_int);
}
