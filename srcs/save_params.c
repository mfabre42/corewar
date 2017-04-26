/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:32:42 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/26 21:14:43 by mafabre          ###   ########.fr       */
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

void	save_params(int ac, char **av, t_convert *arena)
{
	int			i;
	t_params	param;

	i = 1;
	param.np = 0;
	while (i < ac)
	{
		if (ft_strstr(av[i], ".cor") != NULL)
			param.np++;
		i++;
	}
	if (param.np < 0 || param.np > 4)
		exit(0);
	i = 1;
	while (i < ac)
	{
		if (i < ac - 1 && ft_strstr(av[i], "-d") && ft_strlen(av[i]) == 2)
			save_dump(av[++i], &param);
		if (i < ac - 1 && ft_strstr(av[i], "-n") && ft_strlen(av[i]) == 2)
			save_number(av[++i], &param);
		if (ft_strstr(av[i], ".cor") != NULL)
			save_file(av[i], &param, &arena);
		i++;
	}
}
