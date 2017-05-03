/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/03 16:56:07 by mafabre          ###   ########.fr       */
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
	// unsigned int qwerty;

	//init_vm(arena, param);
	// qwerty = hex_to_int(0x0e, 0x68, 0x36, 0xea);
	// printf("Coucou = %d\n", qwerty);
	// while (i < MEM_SIZE)
	// {
	// 	if (i % 64 == 0)
	// 		printf("\n");
	// 	printf("%02x ", map.arena[i]);
	// 	i++;
	// }
	play_game(&map);
	// indirect_store(&map, map.player[0].process);
	// indirect_store(&map, map.player[0].process);
	// indirect_store(&map, map.player[0].process);
	// indirect_store(&map, map.player[0].process);
	// indirect_store(&map, map.player[0].process);
	// indirect_store(&map, map.player[0].process);
	// indirect_store(&map, map.player[0].process);
	// indirect_store(&map, map.player[0].process);
	// indirect_store(&map, map.player[0].process);
	// indirect_store(&map, map.player[0].process);
	// indirect_store(&map, map.player[0].process);
	// indirect_store(&map, map.player[0].process);
	printf("After :\n");
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printf("\n");
		printf("%02x ", map.arena[i]);
		i++;
	}
	return (0);
}
