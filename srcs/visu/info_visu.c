/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 04:55:24 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/26 19:48:57 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_resize(t_visu *visu)
{
	getmaxyx(stdscr, visu->row, visu->col);
	if (visu->row <= 72 || visu->col <= 225)
	{
		clear();
		endwin();
		ft_printf("La taille du visualisateur est trop petite.\n");
		exit(0);
	}
}

void	info_joueur2(t_visu *visu, t_map *map, int i)
{
	if (map->player[i].number == 2)
	{
		attron(COLOR_PAIR(2));
		mvprintw(9, 198, map->player[i].name);
		mvprintw(10, 198, "Num joueur : %d", map->player[i].number);
		mvprintw(11, 198, "Dernier live : %d", map->player[i].last_live);
		attroff(COLOR_PAIR(2));
	}
	if (map->player[i].number == 3)
	{
		attron(COLOR_PAIR(3));
		mvprintw(15, 198, map->player[i].name);
		mvprintw(16, 198, "Num joueur : %d", map->player[i].number);
		mvprintw(17, 198, "Dernier live : %d", map->player[i].last_live);
		attroff(COLOR_PAIR(3));
	}
	if (map->player[i].number == 4)
	{
		attron(COLOR_PAIR(4));
		mvprintw(21, 198, map->player[i].name);
		mvprintw(22, 198, "Num joueur : %d", map->player[i].number);
		mvprintw(23, 198, "Dernier live : %d", map->player[i].last_live);
		attroff(COLOR_PAIR(4));
	}
}

void	info_joueur(t_visu *visu, t_map *map)
{
	int		i;

	i = 0;
	while (i < map->nb_player)
	{
		if (map->player[i].number == 1)
		{
			attron(COLOR_PAIR(1));
			mvprintw(3, 198, map->player[i].name);
			mvprintw(4, 198, "Num joueur : %d", map->player[i].number);
			mvprintw(5, 198, "Dernier live : %d", map->player[i].last_live);
			attroff(COLOR_PAIR(1));
		}
		info_joueur2(visu, map, i);
		i++;
	}
}

void	info_map(t_map *map)
{
	mvprintw(30, 198, "Cycle : %d", map->cycle);
	mvprintw(31, 198, "Prochain check : %d", map->next_ctd);
	mvprintw(32, 198, "Cycle to die :      ");
	mvprintw(32, 198, "Cycle to die : %d", map->cycle_to_die);
	mvprintw(33, 198, "Cycle delta : %d", CYCLE_DELTA);
	mvprintw(34, 198, "Nombre live :             ");
	mvprintw(34, 198, "Nombre live : %d", map->nb_live);
	mvprintw(35, 198, "Nombre de check : %d / %d", map->check, MAX_CHECKS);
}
