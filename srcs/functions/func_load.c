/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:31:28 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/15 21:39:09 by acoupleu         ###   ########.fr       */
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
		ocp = ocp_master((int)map->arena[(pos + 1) % MEM_SIZE]);
		if (ocp.param1 == 'D')
		{
			if (!is_register((int)map->arena[(pos + 6) % MEM_SIZE]))
			{
				fail_func(proc, 7, 1);
				return ;
			}
			reg_nbr = (int)map->arena[(pos + 6) % MEM_SIZE];
			proc->reg[reg_nbr - 1] = hex_to_int(map->arena[(pos + 2) % MEM_SIZE], map->arena[(pos + 3) % MEM_SIZE],
			map->arena[(pos + 4) % MEM_SIZE], map->arena[(pos + 5) % MEM_SIZE]);
			// printf("Load: emplacement d'arene : %02x %02x %02x %02x %02x %02x %02x Valeur direct load: %d dans le registre n: %d pos: %d au tour: %d\n",
			// map->arena[(pos) % MEM_SIZE],
			// map->arena[(pos + 1) % MEM_SIZE],
			// map->arena[(pos + 2) % MEM_SIZE],
			// map->arena[(pos + 3) % MEM_SIZE],
			// map->arena[(pos + 4) % MEM_SIZE],
			// map->arena[(pos + 5) % MEM_SIZE],
			// map->arena[(pos + 6) % MEM_SIZE],
			// hex_to_int(map->arena[(pos + 2) % MEM_SIZE], map->arena[(pos + 3) % MEM_SIZE],
			// map->arena[(pos + 4) % MEM_SIZE], map->arena[(pos + 5) % MEM_SIZE]),
			// reg_nbr - 1,
			// pos,
			// map->cycle);
			proc->pc = proc->pc + 7;
		}
		else if (ocp.param1 == 'I')
		{
			if (!is_register((int)map->arena[(pos + 4) % MEM_SIZE]))
			{
				fail_func(proc, 5, 1);
				return ;
			}
			reg_nbr = (int)map->arena[(pos + 4) % MEM_SIZE];
			proc->reg[reg_nbr - 1] = (short)hex_to_int(0x00, 0x00,
				map->arena[(pos + 2) % MEM_SIZE],
				map->arena[(pos + 3) % MEM_SIZE]);
			printf("\nLoad: Valeur direct load: %d dans le registre n: %d\n\n", hex_to_int(0x00,
				0x00, map->arena[(pos + 2) % MEM_SIZE], map->arena[(pos + 3) % MEM_SIZE]) % IDX_MOD, reg_nbr - 1);
			proc->pc = proc->pc + 5;
		}
		proc->carry = 1;
	}
}
