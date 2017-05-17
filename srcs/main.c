/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/17 18:41:18 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	notif_winner(t_map *map)
{
	int		winner;

	winner = check_last_survivor(map);
	// ft_printf("And the winner is *drum roll* %s !!",
	// map->player[winner].name);
}

int		main(int ac, char **av)
{
	t_map		map;

	save_params(ac, av, &map);
	play_game(&map);
	int i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
			printf("\n");
		printf("%02x ", map.arena[i]);
		i++;
	}
	notif_winner(&map);
	return (0);
}
