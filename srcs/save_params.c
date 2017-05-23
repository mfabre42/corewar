/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:32:42 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/23 15:18:59 by aleveque         ###   ########.fr       */
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

void	check_n_np(int ac, char **av, t_params *param)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strstr(av[i], ".cor") != NULL)
			param->nb_player++;
		if (i < ac - 1 && ft_strcmp(av[i], "-n") == 0)
		{
			i++;
			if (ft_strcmp(av[i], "1") == 0)
				param->p1 += 1;
			else if (ft_strcmp(av[i], "2") == 0)
				param->p2 += 1;
			else if (ft_strcmp(av[i], "3") == 0)
				param->p3 += 1;
			else if (ft_strcmp(av[i], "4") == 0)
				param->p4 += 1;
		}
		if (ft_strstr(av[i], ".cor") == NULL && ft_strcmp(av[i], "-n") != 0 &&
		ft_strcmp(av[i], "-d") != 0 && ft_strcmp(av[i - 1], "-n") != 0 &&
		ft_strcmp(av[i - 1], "-d") != 0 && ft_strcmp(av[i], "-m"))
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
	if (!(map->arena = (unsigned char *)ft_memalloc(sizeof(unsigned char)
		* (MEM_SIZE + 1))))
		error_malloc();
	map->cycle = 1;
	map->nb_live = 0;
	map->cycle_to_die = CYCLE_TO_DIE;
	map->next_ctd = CYCLE_TO_DIE;
	map->check = 0;
	map->dump = -1;
	map->mute = 0;
}

void	save_params(int ac, char **av, t_map *map, int i)
{
	t_params	param;

	init_params(&param, map);
	check_n_np(ac, av, &param);
	if (param.nb_player <= 0 || param.nb_player > 4)
		error(1);
	init_player(&param, map);
	while (++i < ac)
	{
		param.n = 0;
		if (i < ac - 1 && ft_strcmp(av[i], "-d") == 0)
			save_dump(av[++i], &param, map);
		if (i == ac - 1 && ft_strcmp(av[i], "-d") == 0)
			save_dump("-1", &param, map);
		if (ft_strcmp(av[i], "-m") == 0)
			map->mute = 1;
		if (i < ac - 2 && ft_strcmp(av[i], "-n") == 0)
		{
			save_number(av[++i], &param);
			i++;
		}
		if (i == ac - 2 && ft_strcmp(av[i], "-n") == 0)
			save_number("-1", &param);
		if (ft_strstr(av[i], ".cor") != NULL)
			save_file(av[i], &param, map);
	}
}
