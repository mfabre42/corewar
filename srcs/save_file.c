/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:35:01 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/02 12:06:41 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

void		save_file(char *file, t_params *param, unsigned char *arena)
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
	// i = 1;
	// while (i < PROG_NAME_LENGTH/4 + 1)
	// {
	// 	printf("%c", tab[i].c_char[0]);
	// 	printf("%c", tab[i].c_char[1]);
	// 	printf("%c", tab[i].c_char[2]);
	// 	printf("%c", tab[i].c_char[3]);
	// 	i++;
	// }
	// while (i < COMMENT_LENGTH/4 + PROG_NAME_LENGTH/4 + 2)
	// {
	// 	printf("%c", tab[i].c_char[0]);
	// 	printf("%c", tab[i].c_char[1]);
	// 	printf("%c", tab[i].c_char[2]);
	// 	printf("%c", tab[i].c_char[3]);
	// 	i++;
	// }
	// while (i < COMMENT_LENGTH/4 + PROG_NAME_LENGTH/4 + CHAMP_MAX_SIZE/4 + 2)
	// {
	// 	printf("%02x", tab[i].c_char[0]);
	// 	printf("%02x", tab[i].c_char[1]);
	// 	printf("%02x", tab[i].c_char[2]);
	// 	printf("%02x ", tab[i].c_char[3]);
	// 	i++;
	// }
	close(fd);
	init_map(tab, param, )
	send_in_arena(tab, param, arena);
}
