/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/19 18:19:27 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		save_file(char *file, int *cor)
{
	t_convert	convert;
	int			fd;
	int			ret;
	char		tmp;
	int			i;

	ret = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_printf("exit\n");
	while ((ret = read(fd, convert.c_char, BUF_SIZE)) > 0)
	{
		tmp = convert.c_char[0];
		convert.c_char[0] = convert.c_char[3];
		convert.c_char[3] = tmp;
		tmp = convert.c_char[1];
		convert.c_char[1] = convert.c_char[2];
		convert.c_char[2] = tmp;
		cor[i] = convert.c_int;
		ft_bzero(convert.c_char, 4);
		i++;
	}
	close(fd);
	return (i);
}

int		main(int ac, char **av)
{
	int		*cor;
	int		i;
	int		j;

	cor = (int *)malloc(sizeof(int) * 800);
	i = save_file(av[1], cor);
	j = 0;
	while (j < i)
	{
		printf("%s ", ft_itoa_base(cor[j], 16));
		j++;
	}
}
