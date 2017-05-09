/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:13:28 by anonymou          #+#    #+#             */
/*   Updated: 2017/05/09 17:04:53 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	kill_player(t_map *map, int n_player)
{
	t_player	player;
	t_process	*tmp1;
	t_process	*tmp2;
	t_process	*tmp3;

	player = map->player[n_player];
	tmp1 = player.process;
	tmp2 = NULL;
	while (tmp1 != NULL && tmp1 != process)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	if (tmp1 != NULL)
	{
		tmp3 = tmp1->next;
		ft_lstdelone(&tmp1);
		map->player[player].process_nbr--;
		if (tmp2 != NULL)
			tmp2->next = tmp3;
		else
			map->player[player].process = tmp3;
	}
}
