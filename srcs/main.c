/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/18 19:08:16 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	notif_winner(t_map *map)
{
	int		winner;

	winner = check_last_survivor(map);
	// printf("And the winner is n : %d *drum roll* %s !!\n",
	// winner,
	// map->player[winner].name);
	ft_printf("And the winner is n : %d *drum roll* %s !!\n",
	winner + 1,
	map->player[winner].name);
}

int		main(int ac, char **av)
{
	t_map		map;

	save_params(ac, av, &map);
	play_game(&map);
	int i = 0;
	if (map.dump != -1)
	{
		while (i < MEM_SIZE)
		{
			if (i % 64 == 0 && i != 0)
				ft_printf("\n");
			ft_printf("%02x ", map.arena[i]);
			i++;
		}
		ft_printf("\n");
	}
	if (map.cycle_to_die < 0 || is_alive(&map) == 0)
		notif_winner(&map);
	return (0);
}
