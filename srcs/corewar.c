/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:23:26 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/04 19:28:36 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_cycle(t_process *tmp, t_map *map, int player)
{
	if (tmp->cycle == 0)
	{
		indirect_store(map, tmp);
	}
	else if (tmp->cycle > 0)
		tmp->cycle--;
	else
		printf("t'a fait du caca\n");
}

void	play_game(t_map *map)
{
	int			player;
	t_process	*tmp;

	while (map->cycle < 325)
	{
		player = map->nb_player - 1;
		while (player > 0)
		{
			tmp = map->player[player].process;
			while (tmp != NULL)
			{
				printf("player : %d,%p\n", player, tmp);
				ft_cycle(tmp, map, player);
				tmp = tmp->next;
			}
			player--;
		}
		map->cycle++;
	}
}
