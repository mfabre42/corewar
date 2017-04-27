/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 20:49:40 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/27 16:02:08 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

void	get_n(t_params *param)
{
	if (param->p1 != 1)
	{
		param->n = 1;
		param->p1 = 1;
	}
	else if (param->p2 != 1)
	{
		param->n = 2;
		param->p2 = 1;
	}
	else if (param->p3 != 1)
	{
		param->n = 3;
		param->p3 = 1;
	}
	else if (param->p4 != 1)
	{
		param->n = 4;
		param->p4 = 1;
	}
}

void	send_in_arena(t_convert *tab, t_params *param, unsigned char *arena)
{
	int	i;
	int	j;

	if (param->n == 0)
		get_n(param);
	printf("DDDDDDD %d\n", param->n);
	i = MEM_SIZE * (param->n - 1) / param->np;
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
