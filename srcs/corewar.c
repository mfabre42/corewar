/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:23:26 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/05 16:38:08 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

struct s_proto_func init_tab()
{
	static t_proto_func func_table[16] = {
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

	return (func_table);
}

void	do_func(t_map *map, t_process *tmp, int func, int player)
{
	t_proto_func tab;

	tab = init_tab();
	if (func >= 1 && func <= 16)
	{
		if (func == 12)
			forkniquer(map, tmp, player);
		else if (func == 15)
			lfork(map, tmp, player);
		else
		{
			(*tab[func])(map, tmp);
		}
	}
	else
	{
		tmp->pc++;
	}
}

void	ft_cycle(t_process *tmp, t_map *map, int player)
{
	int ft;

	if (tmp->ft >= 1 && tmp->ft <= 16)
		ft = tmp->ft;
	else
		ft = (int)map->arena[tmp->start + tmp->pc];
	if (tmp->cycle == 0)
	{
		do_func(tmp, ft, player);
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
		while (player >= 0)
		{
			tmp = map->player[player].process;
			while (tmp != NULL)
			{
				// printf("player : %d,%p\n", player, tmp);
				ft_cycle(tmp, map, player);
				tmp = tmp->next;
			}
			player--;
		}
		map->cycle++;
	}
}
