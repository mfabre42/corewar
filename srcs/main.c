/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/15 17:40:10 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_map		map;

	int i = 0;
	printf("yo\n");
	save_params(ac, av, &map);
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
	play_game(&map, ft_atoi(av[2]));
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
