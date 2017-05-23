/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:23:26 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/23 16:21:59 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	(*init_tab(int ft))(t_map *, t_process*)
{
	int					i;
	static t_proto_func	func_table[14] = {
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

	i = -1;
	while (++i < 14)
	{
		if (func_table[i].num_func == ft)
			return (func_table[i].func);
	}
	return (func_table[ft].func);
}

void	do_func(t_map *map, t_process *tmp, int ft, int player)
{
	// if (map->cycle == 21490 || map->cycle == 21489 || map->cycle == 21491)
	// 	printf("ft = %d\n", ft);
	if (ft >= 1 && ft <= 16)
	{
		if (ft == 12)
			forkniquer(map, tmp, player);
		else if (ft == 15)
			lfork(map, tmp, player);
		else
			(init_tab(ft))(map, tmp);
	}
	else
		tmp->pc++;
}

void	ft_cycle(t_process *tmp, t_map *map, int player)
{
	int ft;

	if (tmp->ft >= 1 && tmp->ft <= 16)
		ft = tmp->ft;
	else
	{
		ft = (int)
		map->arena[
		(tmp->start
		+ tmp->pc)
		% MEM_SIZE];
	}
	if (tmp->cycle == 0)
	{
		// printf("ft : %d\n", ft);
		do_func(map, tmp, ft, player);
	}
	else if (tmp->cycle > 0)
		tmp->cycle--;
}

void	play_game(t_map *map)
{
	int			player;
	t_process	*tmp;

	while (1 && (map->dump == -1 || map->cycle <= map->dump))
	{
		player = map->nb_player - 1;
		while (player >= 0)
		{
			tmp = map->player[player].process;
			//	printf("player:%d ,point: %p\n",player, tmp);
			while (tmp != NULL)
			{
			//	printf("player : %d, cycle : %d, pc : %d, start : %d\n", player, map->cycle, tmp->pc, tmp->start);
				ft_cycle(tmp, map, player);
				tmp = tmp->next;
			}
			player--;
		}
		map->cycle++;
		cycle_to_die(map);
		// printf("\n\n");
		if (map->cycle_to_die <= 0 || is_alive(map) == 0)
			break ;
	}
}
