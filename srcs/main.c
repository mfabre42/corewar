/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/16 20:17:58 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_map		map;

	save_params(ac, av, &map);
	play_game(&map, ft_atoi(av[4]));
	int i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
			printf("\n");
		printf("%02x ", map.arena[i]);
		i++;
	}
	return (0);
}
