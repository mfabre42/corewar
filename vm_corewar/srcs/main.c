/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/06/08 15:59:16 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_map(t_map *map)
{
	int			i;

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
	free(ARENA_CLAIM);
	free(ARENA);
}

void	intro_contest(t_map *map)
{
	int		i;

	i = 0;
	ft_printf("Voici les champions qui entrent dans l'arene:\n");
	while (i < map->nb_player)
	{
		if (i == 0)
			ft_printf("A ma droite, le premier concurant, l'exeptionnel : ");
		else if (i == 1)
			ft_printf("A ma gauche, l'imbattable                        : ");
		else if (i == 2)
			ft_printf("Au milieu de l'arene je vous présente            : ");
		else if (i == 3)
			ft_printf("Et pour finir, voici le monstrueux               : ");
		ft_printf("%s (%s)\n", map->player[i].name, map->player[i].comm);
		i++;
	}
}

void	notif_winner(t_map *map)
{
	int	winner;

	winner = check_last_survivor(map);
	ft_printf("And the winner is n : %d *drum roll* %s !!\n",
	winner + 1,
	map->player[winner].name);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->dump != -1 || map->ndump != 0)
	{
		while (i < MEM_SIZE)
		{
			if (i % 32 == 0 && i != 0)
				ft_printf("\n");
			ft_printf("%02x ", ARENA[i]);
			i++;
		}
		ft_printf("\n");
	}
	if (map->ndump != 0)
	{
		ft_printf("Cycle actuel: %d, appuyez sur entrer pour continuer\n",
		map->cycle);
		pauses();
	}
}

int		main(int ac, char **av)
{
	t_map		map;

	if (ac == 1)
		print_usage();
	save_params(ac, av, &map);
	if (map.visu != 1)
		intro_contest(&map);
	play_game(&map);
	if (map.visu == 1)
		display_winner(&map);
	else
		print_map(&map);
	if (map.cycle_to_die < 0 || is_alive(&map) == 0)
		notif_winner(&map);
	free_map(&map);
	return (0);
}
