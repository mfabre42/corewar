/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:31:28 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/24 01:44:06 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	direct_load(t_map *map, t_process *proc)
{
	int		pos;
	t_ocp	ocp;
	int		reg_nbr;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 3, 2, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)ARENA[(pos + 1) % MEM_SIZE]);
		if (ocp.param1 == 'D')
		{
			if (!is_reg((int)ARENA[(pos + 6) % MEM_SIZE], proc, 7))
				return ;
			reg_nbr = (int)ARENA[(pos + 6) % MEM_SIZE];
			proc->reg[reg_nbr - 1] = hex_to_int(ARENA[(pos + 2) % MEM_SIZE], ARENA[(pos + 3) % MEM_SIZE],
			ARENA[(pos + 4) % MEM_SIZE], ARENA[(pos + 5) % MEM_SIZE]);
			proc->pc = proc->pc + 7;
		}
		else if (ocp.param1 == 'I')
		{
			if (!is_reg((int)ARENA[(pos + 4) % MEM_SIZE], proc, 5))
				return ;
			reg_nbr = (int)ARENA[(pos + 4) % MEM_SIZE];
			proc->reg[reg_nbr - 1] = (short)hex_to_int(0x00, 0x00,
				ARENA[(pos + 2) % MEM_SIZE],
				ARENA[(pos + 3) % MEM_SIZE]);
			proc->pc = proc->pc + 5;
		}
		else
		{
			proc->pc = proc->pc + 5;
			return ;
		}
		proc->carry = !proc->reg[reg_nbr - 1];
	}
}
