/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/23 22:27:33 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_map(t_map *map)
{
	int			i;
	t_process	*tmp;

	i = 0;
	while (i < map->nb_player)
	{
		if (map->player[i].process != NULL)
			ft_lstdel(&map->player[i].process);
		free(map->player[i].name);
		free(map->player[i].comm);
		i++;
	}
	free(map->player);
	free(ARENA);
}

void	notif_winner(t_map *map)
{
	int		winner;

	winner = check_last_survivor(map);
	ft_printf("And the winner is n : %d *drum roll* %s !!\n",
	winner + 1,
	map->player[winner].name);
}

int		main(int ac, char **av)
{
	int			i;
	t_map		map;

	if (ac == 1)
		print_usage();
	i = 0;
	save_params(ac, av, &map, 0);
	play_game(&map);
	if (map.dump != -1)
	{
		printf("\n");
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
	free_map(&map);
	return (0);
}
