/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:23:26 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/04 23:39:23 by acoupleu         ###   ########.fr       */
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

t_proto_func func_table[16] = {
	{1, &live},
	{2, &direct_load},
	{3, &direct_store},
	{4, &addition},
	{5, &substraction},
	{6, &func_and},
	{7, &func_or},
	{8, &func_xor},
	{9, &jump_if_zero},
	{10, &indirect_load},
	{11, &indirect_store},
	{13, &ldirect_load},
	{14, &lindirect_load},
	{16, &aff_char}
};
