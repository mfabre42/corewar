/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/08 14:58:36 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_params	param;
	t_map		map;

	map.arena = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	map.nb_live = 0;
	ft_bzero(map.arena, MEM_SIZE);
	int i = 0;
	param = save_params(ac, av, param, &map);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
		{
			printf("\n");
			break;
		}
		printf("%02x ", map.arena[i]);
		i++;
	}
	play_game(&map);
	// indirect_store(&map, map.player[0].process);
	printf("\n\n");
	printf("After :\n");
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
		{
			printf("\n");
			// break;
		}
		printf("%02x ", map.arena[i]);
		i++;
	}
	return (0);
}
