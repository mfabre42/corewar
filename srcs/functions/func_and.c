/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:53:14 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/23 23:26:59 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	func_and2(t_map *map, t_process *proc, int param1, int pc, t_ocp ocp)
{

}

void		func_and(t_map *map, t_process *proc)
{
	t_
	int		param1;

	if (proc->do_funk == 1)
		do_funk(proc, 4, 6, 0);
	else
	{
		do_funk(proc, 0, 0, 1);
		pc = 2;
		bin->pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[(bin->pos + 1) % MEM_SIZE]);
		if (ocp.param1 == 'R')
		{
			if (!is_register(((int)map->arena[(bin->pos + pc) % MEM_SIZE])))
			{
				fail_func(proc, 3, 1);
				return ;
			}
			param1 = proc->reg[(int)map->arena[(bin->pos + pc) % MEM_SIZE] - 1];
			pc += 1;
		}
		else if (ocp.param1 == 'I')
		{
			param1 = (short)hex_to_int(0x00, 0x00, map->arena[(bin->pos + 2) % MEM_SIZE], map->arena[(bin->pos + 3) % MEM_SIZE]);
			pc += 2;
		}
		else if (ocp.param1 == 'D')
		{
			param1 = hex_to_int(map->arena[(bin->pos + 2) % MEM_SIZE], map->arena[(bin->pos + 3) % MEM_SIZE],
				map->arena[(bin->pos + 4) % MEM_SIZE], map->arena[(bin->pos + 5) % MEM_SIZE]);
			pc += 4;
		}
		if (ocp.param2 == 'R')
		{
			if (!is_register(((int)map->arena[(bin->pos + pc) % MEM_SIZE])))
			{
				fail_func(proc, pc + 1, 1);
				return ;
			}
			param1 = param1 & proc->reg[(int)map->arena[(bin->pos + pc) % MEM_SIZE] - 1];
			pc += 1;
		}
		else if (ocp.param2 == 'I')
		{
			param1 = param1 & (short)hex_to_int(0x00, 0x00, map->arena[(bin->pos + pc) % MEM_SIZE], map->arena[(bin->pos + pc + 1) % MEM_SIZE]);
			pc += 2;
		}
		else if (ocp.param2 == 'D')
		{
			param1 = param1 & hex_to_int(map->arena[(bin->pos + pc) % MEM_SIZE], map->arena[(bin->pos + pc + 1) % MEM_SIZE],
				map->arena[(bin->pos + pc + 2) % MEM_SIZE], map->arena[(bin->pos + pc + 3) % MEM_SIZE]);
			pc += 4;
		}
		if (!is_register(((int)map->arena[(bin->pos + pc) % MEM_SIZE])))
		{
			fail_func(proc, pc + 1, 1);
			return ;
		}
		if ((ocp.param1 == 'R' || ocp.param1 == 'I' || ocp.param1 == 'D') &&
			(ocp.param2 == 'R' || ocp.param2 == 'I' || ocp.param2 == 'D'))
		{
			proc->reg[(int)map->arena[(bin->pos + pc) % MEM_SIZE] - 1] = param1;
			proc->pc += pc + 1;
			proc->carry = !param1;
		}
		else
			proc->pc = proc->pc + 5;
	}
}
