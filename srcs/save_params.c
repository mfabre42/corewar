/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:32:42 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/02 13:08:55 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

void	save_dump(char *av, t_params *param)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			i++;
		else
			exit(0);
	}
	param->d = ft_atoi(av);
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
			exit(0);
	}
	if (ft_atoi(av) > 0 && ft_atoi(av) < 5)
		param->n = ft_atoi(av);
	else
		exit(0);
	ft_printf("%d\n", param->n);
}

void	check_n_np(int ac, char **av, t_params *param)
{
	int i;

	i = 0;
	while (i < ac)
	{
		if (ft_strstr(av[i], ".cor") != NULL)
			param->np++;
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
		i++;
	}
	if (param->p1 > 1 || param->p2 > 1 || param->p3 > 1 || param->p4 > 1)
	{
		printf("coucou\n");
		exit(0);
		printf("coucou\n");
	}
}

void	init_params(t_params *param)
{
	param->d = 0;
	param->n = 0;
	param->np = 0;
	param->p1 = 0;
	param->p2 = 0;
	param->p3 = 0;
	param->p4 = 0;
}

t_params	save_params(int ac, char **av, t_params param, t_map *map)
{
	int			i;

	i = 1;
	init_params(&param);
	check_n_np(ac, av, &param);
	if (param.np < 0 || param.np > 4)
		exit(0);
	i = 1;
	while (i < ac)
	{
		param.n = 0;
		if (i < ac - 1 && ft_strcmp(av[i], "-d") == 0)
			save_dump(av[++i], &param);
		if (i < ac - 1 && ft_strcmp(av[i], "-n") == 0)
		{
			save_number(av[++i], &param);
			i++;
		}
		if (ft_strstr(av[i], ".cor") != NULL)
			save_file(av[i], &param, map->arena);
		i++;
	}
	return (param);
}
