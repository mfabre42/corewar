/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:13:28 by anonymou          #+#    #+#             */
/*   Updated: 2017/05/24 02:12:57 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_player(t_map *map, int n_player)
{
	if (map->player[n_player].process != NULL)
		ft_lstdel(&map->player[n_player].process);
	map->player[n_player].in_life = 0;
}

void	kill_process(t_map *map, int i, t_process *proc)
{
	t_process *tmp1;
	t_process *tmp2;
	t_process *tmp3;

	tmp1 = map->player[i].process;
	if (tmp1 == proc)
	{
		tmp2 = tmp1->next;
		ft_lstdelone(&tmp1);
		map->player[i].process = tmp2;
	}
	else
	{
		while (tmp1 != NULL && tmp1 != proc)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		if (tmp1 != NULL)
		{
			tmp3 = tmp1->next;
			ft_lstdelone(&tmp1);
			tmp2->next = tmp3;
		}
	}
}
