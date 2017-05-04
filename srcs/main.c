/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/04 18:38:28 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_params	param;
	t_map		map;

	map.arena = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	ft_bzero(map.arena, MEM_SIZE);
	int i = 0;
	param = save_params(ac, av, param, &map);
	// while (i < MEM_SIZE)
	// {
	// 	if (i % 64 == 0)
	// 		printf("\n");
	// 	printf("%02x ", map.arena[i]);
	// 	i++;
	// }
	play_game(&map);
	// indirect_store(&map, map.player[0].process);
	printf("After :\n");
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			printf("\n");
			break;
		}
		printf("%02x ", map.arena[i]);
		i++;
	}
	return (0);
}
