/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:50:32 by anonymou          #+#    #+#             */
/*   Updated: 2017/05/23 23:36:23 by acoupleu         ###   ########.fr       */
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

void	fail_func(t_process *proc, int pc, int carry)
{
	proc->pc += pc % MEM_SIZE;
	if (carry == 1)
	{
		proc->carry = 0;
	}
}

t_bin	init_bin(t_map *map, t_process *proc)
{
	t_bin	bin;

	bin.pos = proc->start + proc->pc;
	bin.ocp = ocp_master((int)map->arena[(bin.pos + 1) % MEM_SIZE]);
	bin.pc = 0;
	return bin;
}
