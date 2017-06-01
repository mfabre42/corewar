/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:35:01 by mafabre           #+#    #+#             */
/*   Updated: 2017/06/01 20:18:46 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	size(t_convert *tab, int i, int tmp)
{
	int t_t;
	int champ_len;

	t_t = tab[34].c_char[2] << 8;
	t_t = tab[34].c_char[3] | t_t;
	if (t_t == 0)
		error(8);
	champ_len = tmp != 0 ? (i - (COMMENT_LENGTH / 4 + PROG_NAME_LENGTH
	/ 4 + 4)) * 4 + tmp - 4 : (i - (COMMENT_LENGTH / 4 + PROG_NAME_LENGTH / 4
	+ 4)) * 4 + tmp;
	if (t_t != champ_len)
		error(7);
}

void	if_check_np(char **av, t_params *param, int *i)
{
	(*i)++;
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
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strstr(av[i], ".cor") != NULL)
			param->nb_player++;
		if (i < ac - 1 && ft_strcmp(av[i], "-n") == 0)
			if_check_np(av, param, &i);
		if (ft_strstr(av[i], ".cor") == NULL && ft_strcmp(av[i], "-n") != 0 &&
		ft_strcmp(av[i], "-dump") != 0 && ft_strcmp(av[i - 1], "-n") != 0 &&
		ft_strcmp(av[i - 1], "-dump") != 0 && ft_strcmp(av[i], "-m") != 0 &&
		ft_strcmp(av[i], "-a") != 0 && ft_strcmp(av[i], "-v") != 0 &&
		ft_strcmp(av[i], "-s") != 0 && ft_strcmp(av[i - 1], "-s") != 0)
			error(3);
		i++;
	}
	if ((param->p1 > 1 || param->p2 > 1 || param->p3 > 1 || param->p4 > 1) ||
	(param->nb_player == 1 && (param->p2 + param->p3 + param->p4) >= 1) ||
	(param->nb_player == 2 && (param->p3 + param->p4) >= 1) ||
	(param->nb_player == 3 && param->p4 >= 1))
		error(2);
}

void	save_file(char *file, t_params *param, t_map *map, int tmp)
{
	t_convert	convert;
	int			fd;
	int			ret;
	int			i;
	t_convert	*tab;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error(5);
	if (!(tab = (t_convert *)ft_memalloc(sizeof(t_convert) *
		(PROG_NAME_LENGTH / 4 + COMMENT_LENGTH / 4 + CHAMP_MAX_SIZE / 4 + 4))))
		error_malloc();
	while ((ret = read(fd, convert.c_char, BUF_SIZE)) > 0)
	{
		tab[i++] = convert;
		ft_bzero(convert.c_char, 4);
		if (i > 719 || (i == 719 && ret > 2))
			error(6);
		tmp = ret;
	}
	size(tab, i, tmp);
	close(fd);
	send_in_arena(tab, param, map);
	free(tab);
}
