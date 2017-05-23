/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:35:01 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/23 18:06:11 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		save_file(char *file, t_params *param, t_map *map)
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
		error(5);
	//Check nom des joueurs (c'est mal codé comme dab)
	if (!(tab = (t_convert *)ft_memalloc(sizeof(t_convert) * (PROG_NAME_LENGTH / 4
		+ COMMENT_LENGTH / 4 + CHAMP_MAX_SIZE / 4 + 4))))
		error_malloc();
	// printf("taille tab = %d\n", PROG_NAME_LENGTH / 4
	// 	+ COMMENT_LENGTH / 4 + CHAMP_MAX_SIZE / 4 + 4);
	while ((ret = read(fd, convert.c_char, BUF_SIZE)) > 0)
	{
		tab[i++] = convert;
		ft_bzero(convert.c_char, 4);
	}
	// printf("tab size = %d malloc = %d\n", i, (PROG_NAME_LENGTH / 4
	// 	+ COMMENT_LENGTH / 4 + CHAMP_MAX_SIZE / 4));
	close(fd);
	send_in_arena(tab, param, map);
	free(tab);
}
