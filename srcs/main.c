/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/25 20:00:03 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

int		save_file_int(char *file, int *cor)
{
	t_convert	convert;
	int			fd;
	int			ret;
	int			i;
	t_convert	*tab;

	ret = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_printf("exit\n");
	tab = (t_convert *)malloc(sizeof(t_convert) * CHAMP_MAX_SIZE);
	while ((ret = read(fd, convert.c_char, BUF_SIZE)) > 0)
	{
		tab[i] = convert;
		ft_bzero(convert.c_char, 4);
		i++;
	}
	int j = 1;
	while (j < PROG_NAME_LENGTH/4 + 1)
	{
		printf("%c", tab[j].c_char[0]);
		printf("%c", tab[j].c_char[1]);
		printf("%c", tab[j].c_char[2]);
		printf("%c", tab[j].c_char[3]);
		j++;
	}
	while (j < COMMENT_LENGTH/4 + PROG_NAME_LENGTH/4 + 2)
	{
		printf("%c", tab[j].c_char[0]);
		printf("%c", tab[j].c_char[1]);
		printf("%c", tab[j].c_char[2]);
		printf("%c", tab[j].c_char[3]);
		j++;
	}
	while (j < COMMENT_LENGTH/4 + PROG_NAME_LENGTH/4 + CHAMP_MAX_SIZE/4 + 2)
	{
		printf("%02x", tab[j].c_char[0]);
		printf("%02x", tab[j].c_char[1]);
		printf("%02x", tab[j].c_char[2]);
		printf("%02x ", tab[j].c_char[3]);
		j++;
	}
	close(fd);
	return (i);
}

int		main(int ac, char **av)
{
	int		*cor;
	int		i;
	int		j;

	cor = (int *)malloc(sizeof(int) * CHAMP_MAX_SIZE);
	i = save_file_int(av[1], cor);
	j = 0;
	// while (j < i)
	// {
	// 	printf("%s ", res[j]);
	// 	j++;
	// }
}
