/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 01:43:57 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/30 20:52:49 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_term_size_color(t_visu visu)
{
	if (!has_colors() || !can_change_color())
	{
		clear();
		endwin();
		ft_printf("Le terminal ne supporte pas les couleurs\
		ou leur changement\n.");
		exit(0);
	}
	if (visu.row <= 72 || visu.col <= 225)
	{
		clear();
		endwin();
		ft_printf("Veuillez agrandir votre terminal.\n");
		exit(0);
	}
}

void	init_couleur(void)
{
	init_color(5, 250, 250, 250);
	init_pair(1, 1, COLOR_BLACK);
	init_pair(2, 4, COLOR_BLACK);
	init_pair(3, 6, COLOR_BLACK);
	init_pair(4, 3, COLOR_BLACK);
	init_pair(5, 0, COLOR_RED);
	init_pair(6, 0, COLOR_BLUE);
	init_pair(7, 0, COLOR_CYAN);
	init_pair(8, 0, COLOR_YELLOW);
	init_pair(9, 5, COLOR_BLACK);
	init_pair(10, 0, COLOR_MAGENTA);
}

t_visu	init_visu(t_map *map)
{
	t_visu visu;

	map->mute = 1;
	map->mute_aff = 0;
	map->dump = -1;
	map->ndump = 0;
	initscr();
	getmaxyx(stdscr, visu.row, visu.col);
	check_term_size_color(visu);
	start_color();
	init_couleur();
	curs_set(0);
	return (visu);
}
