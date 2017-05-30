/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 20:49:40 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/30 17:34:37 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_player(t_params *param, t_map *map)
{
	int	i;

	i = 0;
	if (!(map->player = (t_player*)malloc(sizeof(t_player) * param->nb_player)))
		error_malloc();
	while (i < param->nb_player)
	{
		if (!(map->player[i].name = (char *)malloc(sizeof(char) *
		PROG_NAME_LENGTH + 1)))
			error_malloc();
		if (!(map->player[i].comm = (char *)malloc(sizeof(char) *
		COMMENT_LENGTH + 1)))
			error_malloc();
		map->player[i].process = NULL;
		map->player[i].in_life = 1;
		map->player[i].last_live = 1;
		map->player[i].number = 0;
		i++;
	}
	map->nb_player = param->nb_player;
}

void	get_n(t_params *param)
{
	if (param->p1 != 1)
	{
		param->n = 1;
		param->p1 = 1;
	}
	else if (param->p2 != 1)
	{
		param->n = 2;
		param->p2 = 1;
	}
	else if (param->p3 != 1)
	{
		param->n = 3;
		param->p3 = 1;
	}
	else if (param->p4 != 1)
	{
		param->n = 4;
		param->p4 = 1;
	}
	if (param->n - 1 > param->nb_player - 1 || param->n - 1 < 0)
		error(2);
}

void	get_name_comment(t_convert *tab, t_params *param, t_map *map, int i)
{
	t_player	tmp;
	int			j;

	j = 1;
	tmp = map->player[param->n - 1];
	while (j < PROG_NAME_LENGTH / 4 + 3 && i < 125)
	{
		tmp.name[i++] = tab[j].c_char[0];
		tmp.name[i++] = tab[j].c_char[1];
		tmp.name[i++] = tab[j].c_char[2];
		tmp.name[i++] = tab[j++].c_char[3];
	}
	tmp.name[i] = '\0';
	j += 2;
	i = 0;
	while (j < COMMENT_LENGTH / 4 + PROG_NAME_LENGTH / 4 + 4 && i < 2045)
	{
		tmp.comm[i++] = tab[j].c_char[0];
		tmp.comm[i++] = tab[j].c_char[1];
		tmp.comm[i++] = tab[j].c_char[2];
		tmp.comm[i++] = tab[j++].c_char[3];
	}
	tmp.comm[i] = '\0';
	map->player[param->n - 1] = tmp;
}

void	check_magic_number(t_convert *tab)
{
	if (hex_to_int(tab[0].c_char[0], tab[0].c_char[1], tab[0].c_char[2],
			tab[0].c_char[3]) != 15369203)
	{
		ft_printf("wrong magic number exit\n");
		exit(0);
	}
}

void	send_in_arena(t_convert *tab, t_params *param, t_map *map)
{
	int	i;
	int	j;

	if (param->n == 0)
		get_n(param);
	map->player[param->n - 1].number = param->n;
	i = MEM_SIZE * (param->n - 1) / param->nb_player;
	get_name_comment(tab, param, map, 0);
	check_magic_number(tab);
	j = COMMENT_LENGTH / 4 + PROG_NAME_LENGTH / 4 + 4;
	map->player[param->n - 1] = init_process(map, param->n - 1, MEM_SIZE *
		(param->n - 1) / param->nb_player);
	while (i < MEM_SIZE - 3 && j < COMMENT_LENGTH / 4 + PROG_NAME_LENGTH / 4 +
		CHAMP_MAX_SIZE / 4 + 4)
	{
		ARENA_CLAIM[i] = map->player[param->n - 1].number;
		ARENA[i++] = tab[j].c_char[0];
		ARENA_CLAIM[i] = map->player[param->n - 1].number;
		ARENA[i++] = tab[j].c_char[1];
		ARENA_CLAIM[i] = map->player[param->n - 1].number;
		ARENA[i++] = tab[j].c_char[2];
		ARENA_CLAIM[i] = map->player[param->n - 1].number;
		ARENA[i++] = tab[j].c_char[3];
		j++;
	}
}
