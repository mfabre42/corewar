/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:57:24 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/16 17:58:05 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	func_xor(t_map *map, t_process *proc)
{
	int		pos;
	t_ocp	ocp;
	int		pc;
	int		param1;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 4, 8, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pc = 2;
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[(pos + 1) % MEM_SIZE]);
		if (ocp.param1 == 'R')
		{
			if (!is_register(((int)map->arena[(pos + pc) % MEM_SIZE])))
			{
				fail_func(proc, 3, 1);
				return ;
			}
			param1 = proc->reg[(int)map->arena[(pos + pc) % MEM_SIZE] - 1];
			pc += 1;
		}
		else if (ocp.param1 == 'I')
		{
			param1 = (short)hex_to_int(0x00, 0x00, map->arena[(pos + 2) % MEM_SIZE], map->arena[(pos + 3) % MEM_SIZE]);
			pc += 2;
		}
		else if (ocp.param1 == 'D')
		{
			param1 = hex_to_int(map->arena[(pos + 2) % MEM_SIZE], map->arena[(pos + 3) % MEM_SIZE],
				map->arena[(pos + 4) % MEM_SIZE], map->arena[(pos + 5) % MEM_SIZE]);
			pc += 4;
		}
		if (ocp.param2 == 'R')
		{
			if (!is_register(((int)map->arena[(pos + pc) % MEM_SIZE])))
			{
				fail_func(proc, pc + 1, 1);
				return ;
			}
			param1 = param1 ^ proc->reg[(int)map->arena[(pos + pc) % MEM_SIZE] - 1];
			pc += 1;
		}
		else if (ocp.param2 == 'I')
		{
			param1 = param1 ^ (short)hex_to_int(0x00, 0x00, map->arena[(pos + pc) % MEM_SIZE], map->arena[(pos + pc + 1) % MEM_SIZE]);
			pc += 2;
		}
		else if (ocp.param2 == 'D')
		{
			param1 = param1 ^ hex_to_int(map->arena[(pos + pc) % MEM_SIZE], map->arena[(pos + pc + 1) % MEM_SIZE],
				map->arena[(pos + pc + 2) % MEM_SIZE], map->arena[(pos + pc + 3) % MEM_SIZE]);
			pc += 4;
		}
		if (!is_register(((int)map->arena[(pos + pc) % MEM_SIZE])))
		{
			fail_func(proc, pc + 1, 1);
			return ;
		}
		proc->reg[(int)map->arena[(pos + pc) % MEM_SIZE] - 1] = param1;
		proc->pc += pc + 1;
		proc->carry = !param1;
		printf("/!\\XOR/!\\Carry %d, start: %d on: %d\n", proc->carry, proc->start, map->arena[proc->start + proc->pc]);
	}
}
