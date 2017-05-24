/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:32:42 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/24 04:00:40 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	save_dump(char *av, t_params *param, t_map *map)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			i++;
		else
			error(4);
	}
	if (map->dump != -1)
		error(4);
	param->dump = ft_atoi(av);
	map->dump = ft_atoi(av);
}

void	save_number(char *av, t_params *param)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			i++;
		else
			error(2);
	}
	if (ft_atoi(av) > 0 && ft_atoi(av) < 5)
		param->n = ft_atoi(av);
	else
		error(2);
}

void	if_check_np (char **av, t_params *param, int *i)
{
	*i++;
	if (ft_strcmp(av[*i], "1") == 0)
		param->p1 += 1;
	else if (ft_strcmp(av[*i], "2") == 0)
		param->p2 += 1;
	else if (ft_strcmp(av[*i], "3") == 0)
		param->p3 += 1;
	else if (ft_strcmp(av[*i], "4") == 0)
		param->p4 += 1;
}


void	check_n_np(int ac, char **av, t_params *param)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strstr(av[i], ".cor") != NULL)
			param->nb_player++;
		if (i < ac - 1 && ft_strcmp(av[i], "-n") == 0)
			if_check_np(av, param, &i);
		if (ft_strstr(av[i], ".cor") == NULL && ft_strcmp(av[i], "-n") != 0 &&
		ft_strcmp(av[i], "-d") != 0 && ft_strcmp(av[i - 1], "-n") != 0 &&
		ft_strcmp(av[i - 1], "-d") != 0 && ft_strcmp(av[i], "-m") != 0 &&
		ft_strcmp(av[i], "-a") != 0)
			error(3);
		i++;
	}
	if ((param->p1 > 1 || param->p2 > 1 || param->p3 > 1 || param->p4 > 1) ||
	(param->nb_player == 1 && (param->p2 + param->p3 + param->p4) >= 1) ||
	(param->nb_player == 2 && (param->p3 + param->p4) >= 1) ||
	(param->nb_player == 3 && param->p4 >= 1))
		error(2);
}

void	init_params(t_params *param, t_map *map)
{
	param->dump = 0;
	param->n = 0;
	param->nb_player = 0;
	param->p1 = 0;
	param->p2 = 0;
	param->p3 = 0;
	param->p4 = 0;
	param->i = 0;
	if (!(ARENA = (unsigned char *)ft_memalloc(sizeof(unsigned char)
		* (MEM_SIZE + 1))))
		error_malloc();
	map->cycle = 1;
	map->nb_live = 0;
	map->cycle_to_die = CYCLE_TO_DIE;
	map->next_ctd = CYCLE_TO_DIE;
	map->check = 0;
	map->dump = -1;
	map->mute = 0;
	map->mute_aff = 0;
}

void	if_save_params(int ac, char **av, t_map *map, t_params *param)
{
	if (param->i < ac - 1 && ft_strcmp(av[param->i], "-d") == 0)
		save_dump(av[++param->i], param, map);
	if (param->i == ac - 1 && ft_strcmp(av[param->i], "-d") == 0)
		save_dump("-1", param, map);
	if (ft_strcmp(av[param->i], "-m") == 0)
		map->mute = 1;
	if (ft_strcmp(av[param->i], "-a") == 0)
		map->mute_aff = 1;
	if (param->i < ac - 2 && ft_strcmp(av[param->i], "-n") == 0)
	{
		save_number(av[++param->i], param);
		param->i++;
	}
	if (param->i >= ac - 2 && ft_strcmp(av[param->i], "-n") == 0)
		save_number("-1", param);
	if (ft_strstr(av[param->i], ".cor") != NULL)
		save_file(av[param->i], param, map);
}

void	save_params(int ac, char **av, t_map *map)
{
	t_params	param;

	init_params(&param, map);
	check_n_np(ac, av, &param);
	if (param.nb_player <= 0 || param.nb_player > 4)
		error(1);
	init_player(&param, map);
	while (++param.i < ac)
	{
		param.n = 0;
		if_save_params(ac, av, map, &param);
	}
}
