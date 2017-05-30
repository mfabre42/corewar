/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:26:28 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/23 23:41:30 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	jump_if_zero(t_map *map, t_process *proc)
{
	int	pos;
	int	result;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 18, 9, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		if (proc->carry == 1)
		{
			result = (short)hex_to_int(0x00, 0x00, ARENA[(pos + 1) %
				MEM_SIZE],
				ARENA[(pos + 2) % MEM_SIZE]);
			proc->pc = proc->pc + result % IDX_MOD;
		}
		else
			proc->pc += 3;
	}
}
