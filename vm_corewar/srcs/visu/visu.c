/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 03:55:38 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/31 19:06:31 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_proc_pc2(t_map *map, t_process *tmp, int y, int x)
{
	if (ARENA_CLAIM[(tmp->pc + tmp->start) % MEM_SIZE] + 4 > 4)
	{
		attron(COLOR_PAIR(ARENA_CLAIM[(tmp->pc + tmp->start) % MEM_SIZE] + 4));
		mvprintw(y, x, "%.2x", ARENA[(tmp->pc + tmp->start) % MEM_SIZE]);
		attroff(COLOR_PAIR(ARENA_CLAIM[(tmp->pc + tmp->start) % MEM_SIZE] + 4));
	}
	else
	{
		attron(COLOR_PAIR(10));
		mvprintw(y, x, "%.2x", ARENA[(tmp->pc + tmp->start) % MEM_SIZE]);
		attroff(COLOR_PAIR(10));
	}
}

static void	print_proc_pc(t_map *map, int i, int y, int x)
{
	int			player;
	t_process	*tmp;

	player = 0;
	while (player < map->nb_player)
	{
		tmp = map->player[player].process;
		while (tmp != NULL)
		{
			if ((tmp->pc + tmp->start) % MEM_SIZE == i)
			{
				print_proc_pc2(map, tmp, y, x);
				break ;
			}
			tmp = tmp->next;
		}
		player++;
	}
}

static void	print_arena_content(t_map *map, int i, int y, int x)
{
	if (ARENA_CLAIM[i])
	{
		attron(COLOR_PAIR(ARENA_CLAIM[i]));
		mvprintw(y, x, "%02x", ARENA[i]);
		attroff(COLOR_PAIR(ARENA_CLAIM[i]));
	}
	else
	{
		attron(COLOR_PAIR(9));
		mvprintw(y, x, "%02x", ARENA[i]);
		attroff(COLOR_PAIR(9));
	}
}

void		print_arena_visu(t_map *map, t_visu *visu)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 1;
	y = 1;
	while (i < MEM_SIZE)
	{
		check_resize(visu);
		print_arena_content(map, i, y, x);
		print_proc_pc(map, i, y, x);
		x = x + 2;
		mvprintw(y, x, " ");
		x++;
		if (i && (i + 1) % 64 == 0)
		{
			y++;
			x = 1;
		}
		i++;
	}
}

void		display_winner(t_map *map)
{
	int	winner;

	winner = check_last_survivor(map);
	attron(COLOR_PAIR(winner + 1));
	mvprintw(40, 198, "Le joueur %d (%s) a gagné.\n",
	map->player[winner].number, map->player[winner].name);
	refresh();
	sleep(1000);
	endwin();
	curs_set(1);
	exit(0);
}
