/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:13:28 by anonymou          #+#    #+#             */
/*   Updated: 2017/05/17 20:24:40 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_player(t_map *map, int n_player)
{

	printf("KILL player: %d", n_player);
	if (map->player[n_player].process != NULL)
		ft_lstdel(&map->player[n_player].process);
	map->player[n_player].in_life = 0;
}
