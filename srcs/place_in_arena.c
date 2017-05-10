/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_in_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 23:07:14 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/10 19:45:43 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			place_in_arena(t_map *map, int dest, int nbr)
{
	t_convert conv;

	// int i = 0;
	// while (i < MEM_SIZE)
	// {
	// 	if (i % 64 == 0 && i != 0)
	// 	{
	// 		printf("\n");
	// 		// break;
	// 	}
	// 	printf("%02x ", map->arena[i]);
	// 	i++;
	// }
	conv.c_int = nbr;
	map->arena[dest] = conv.c_char[3];
	map->arena[dest + 1] = conv.c_char[2];
	map->arena[dest + 2] = conv.c_char[1];
	map->arena[dest + 3] = conv.c_char[0];
	// printf("After Direct Store\n\n");
	// i = 0;
	// while (i < MEM_SIZE)
	// {
	// 	if (i % 64 == 0 && i != 0)
	// 	{
	// 		printf("\n");
	// 		// break;
	// 	}
	// 	printf("%02x ", map->arena[i]);
	// 	i++;
	// }
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
