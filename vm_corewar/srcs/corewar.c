/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:23:26 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/31 18:58:29 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	(*init_tab(int ft))(t_map *, t_process*)
{
	int					i;
	static t_proto_func	func_table[12] = {
		{1, &live},
		{2, &direct_load},
		{4, &addition},
		{5, &substraction},
		{6, &func_and},
		{7, &func_or},
		{8, &func_xor},
		{9, &jump_if_zero},
		{10, &indirect_load},
		{13, &ldirect_load},
		{14, &lindirect_load},
		{16, &aff_char}
	};

	i = -1;
	while (++i < 12)
	{
		if (func_table[i].num_func == ft)
			return (func_table[i].func);
	}
	return (func_table[ft].func);
}

void	do_func(t_map *map, t_process *tmp, int ft, int player)
{
	if (ft >= 1 && ft <= 16)
	{
		if (ft == 3)
			direct_store(map, tmp, player);
		else if (ft == 11)
			indirect_store(map, tmp, player);
		else if (ft == 12)
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
	{
		ft = tmp->ft;
	}
	else
	{
		ft = (int)ARENA[(tmp->start + tmp->pc) % MEM_SIZE];
	}
	if (tmp->cycle == 0)
	{
		do_func(map, tmp, ft, player);
	}
	else if (tmp->cycle > 0)
		tmp->cycle--;
}

void	play_game(t_map *map)
{
	int			player;
	t_process	*tmp;
	t_visu		visu;

	if (map->visu)
		init_visu(map);
	while (1 && (map->dump == -1 || map->cycle <= map->dump))
	{
		player = map->nb_player;
		while (--player >= 0)
		{
			tmp = map->player[player].process;
			while (tmp != NULL)
			{
				ft_cycle(tmp, map, player);
				tmp = tmp->next;
			}
		}
		map->visu ? print_visu(map, &visu) : 0;
		map->ndump != 0 && (map->cycle % map->ndump == 0) ? print_map(map) : 0;
		map->cycle++;
		cycle_to_die(map);
		if (map->cycle_to_die <= 0 || is_alive(map) == 0)
			break ;
	}
}
