/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 20:49:40 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/26 23:28:37 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

int		check_start(t_params *param)
{
	int i;

	i = 0;
	if (param->np == 1)
		i = 0;
	else if (param->np == 2)
		i = MEM_SIZE * (param->n - 1) / 2;
	else if (param->np == 3)
		i = MEM_SIZE * (param->n - 1) / 3;
	else if (param->np == 4)
		i = MEM_SIZE * (param->n - 1) / 4;
	return (i);
}

void	send_in_arena(t_convert *tab, t_params *param, unsigned char *arena)
{
	int	i;
	int	j;

	i = check_start(param);
	j = COMMENT_LENGTH/4 + PROG_NAME_LENGTH/4 + 4;
	while (i < MEM_SIZE && j < COMMENT_LENGTH/4 + PROG_NAME_LENGTH/4 + CHAMP_MAX_SIZE/4 + 4)
	{
		arena[i++] = tab[j].c_char[0];
		arena[i++] = tab[j].c_char[1];
		arena[i++] = tab[j].c_char[2];
		arena[i++] = tab[j].c_char[3];
		j++;
	}
}
