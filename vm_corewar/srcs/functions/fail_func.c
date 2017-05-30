/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:50:32 by anonymou          #+#    #+#             */
/*   Updated: 2017/05/30 18:07:06 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	do_funk(t_process *proc, int cycle, int ft, int what_to_do)
{
	if (what_to_do == 0)
	{
		proc->cycle = cycle;
		proc->ft = ft;
		proc->do_funk = 0;
	}
	if (what_to_do == 1)
	{
		proc->ft = 0;
		proc->do_funk = 1;
	}
}

int		is_reg(unsigned int reg, t_process *proc, int pc)
{
	if (reg >= 1 && reg <= REG_NUMBER)
		return (1);
	proc->pc += pc;
	return (0);
}

t_bin	init_bin(t_map *map, t_process *proc)
{
	t_bin	bin;

	PPOS = proc->start + proc->pc;
	POCP = ocp_master((int)ARENA[(PPOS + 1) % MEM_SIZE]);
	PPC = 2;
	PREG_NBR = 0;
	return (bin);
}
