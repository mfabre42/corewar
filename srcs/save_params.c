/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:32:42 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/17 17:55:34 by aleveque         ###   ########.fr       */
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
		{
			printf("Error dump number\n");
			exit(0);
		}
	}
	if (map->dump != -1)
	{
		printf("Error dump number\n");
		exit(0);
	}
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
		{
			printf("Error player number\n");
			exit(0);
		}
	}
	if (ft_atoi(av) > 0 && ft_atoi(av) < 5)
		param->n = ft_atoi(av);
	else
	{
		printf("Error player number\n");
		exit(0);
	}
	ft_printf("%d\n", param->n);
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
		ft_strcmp(av[i - 1], "-d") != 0)
		{
			ft_printf("Error argument\n");
			exit(0);
		}
		i++;
	}
	if ((param->p1 > 1 || param->p2 > 1 || param->p3 > 1 || param->p4 > 1) ||
	(param->nb_player == 1 && (param->p2 + param->p3 + param->p4) >= 1) ||
	(param->nb_player == 2 && (param->p3 + param->p4) >= 1) ||
	(param->nb_player == 3 && param->p4 >= 1))
	{
		ft_printf("Error player number\n");
		exit(0);
	}
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
	if (!(map->arena = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE)))
	{
		printf("fail malloc"); //LOL
		exit(0);
	}
	ft_bzero(map->arena, MEM_SIZE);
	map->cycle = 1;
	map->nb_live = 0;
	map->cycle_to_die = CYCLE_TO_DIE;
	map->next_ctd = CYCLE_TO_DIE;
	map->check = 0;
	map->dump = -1;
}

void		save_params(int ac, char **av, t_map *map)
{
	t_params	param;
	int			i;

	i = 1;
	init_params(&param, map);
	check_n_np(ac, av, &param);
	if (param.nb_player <= 0 || param.nb_player > 4)
	{
		printf("mauvais nbr de joueur\n");
		exit(0);
	}
	init_player(&param, map);
	while (i < ac)
	{
		param.n = 0;
		if (i < ac - 1 && ft_strcmp(av[i], "-d") == 0)
			save_dump(av[++i], &param, map);
		if (i < ac - 1 && ft_strcmp(av[i], "-n") == 0)
		{
			save_number(av[++i], &param);
			i++;
		}
		if (ft_strstr(av[i], ".cor") != NULL)
			save_file(av[i], &param, map);
		i++;
	}
	// printf("dump: %d\n", map->dump);
}
