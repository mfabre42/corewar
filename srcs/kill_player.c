/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:13:28 by anonymou          #+#    #+#             */
/*   Updated: 2017/05/16 20:13:23 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_player(t_map *map, int n_player)
{
	t_player	player;

	ft_lstdel(&map->player[n_player].process);
	map->player[n_player].in_life = 0;
}
