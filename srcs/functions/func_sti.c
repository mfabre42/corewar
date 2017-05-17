/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:15:10 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/17 20:03:04 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	indirect_store(t_map *map, t_process *proc)
{
	int		reg_nbr;
	int		pos;
	int		result;
	t_ocp	ocp;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 23, 11, 0);
	}
	else
	{
		// printf("Le joueur, a fait un sti cycle:%d\n", map->cycle);
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		printf("PC avant: %d a l'adresse %02x\n", proc->pc, map->arena[pos]);
		ocp = ocp_master((int)map->arena[(pos + 1) % MEM_SIZE]);
		if (!is_register((int)map->arena[(pos + 2) % MEM_SIZE]))
		{
			fail_func(proc, 5, 0);
			return ;
		}
		reg_nbr = (int)map->arena[(pos + 2) % MEM_SIZE];
		if (ocp.param2 == 'R' && ocp.param3 == 'D')
		{
			if (!is_register((int)map->arena[(pos + 3) % MEM_SIZE]))
			{
				fail_func(proc, 6, 0);
				return ;
			}
			result = proc->reg[(int)map->arena[(pos + 3) % MEM_SIZE] - 1];
			result += (short)hex_to_int(0x00, 0x00, map->arena[(pos + 4) % MEM_SIZE],
				map->arena[(pos + 5) % MEM_SIZE]);
			proc->pc = proc->pc + 6;
		}
		else if (ocp.param2 == 'R' && ocp.param3 == 'R')
		{
			if (!is_register((int)map->arena[(pos + 3) % MEM_SIZE])
				|| !is_register((int)map->arena[(pos + 4) % MEM_SIZE]))
			{
				fail_func(proc, 5, 0);
				return ;
			}
			result = proc->reg[(int)map->arena[(pos + 3) % MEM_SIZE] - 1];
			result += proc->reg[(int)map->arena[(pos + 4) % MEM_SIZE] - 1];
			proc->pc = proc->pc + 5;
		}
		else if ((ocp.param2 == 'D' || ocp.param2 == 'I') && ocp.param3 == 'D')
		{

			result = (short)hex_to_int(0x00, 0x00, map->arena[(pos + 3) % MEM_SIZE], map->arena[(pos + 4) % MEM_SIZE]);
			result += (short)hex_to_int(0x00, 0x00, map->arena[(pos + 5) % MEM_SIZE], map->arena[(pos + 6) % MEM_SIZE]);
			proc->pc = proc->pc + 7;
		}
		else if ((ocp.param2 == 'D' || ocp.param2 == 'I') && ocp.param3 == 'R')
		{
			if (!is_register((int)map->arena[(pos + 5) % MEM_SIZE]))
			{
				fail_func(proc, 6, 0);
				return ;
			}
			result = (short)hex_to_int(0x00, 0x00, map->arena[(pos + 3) % MEM_SIZE], map->arena[(pos + 4) % MEM_SIZE]);
			result += proc->reg[(int)map->arena[(pos + 5) % MEM_SIZE] - 1];
			// printf("short = %d, val registre = %d, result = %d, pos = %d, dest = %d\n", (short)hex_to_int(0x00, 0x00, map->arena[(pos + 3) % MEM_SIZE], map->arena[(pos + 4) % MEM_SIZE]),
			// proc->reg[(int)map->arena[(pos + 5) % MEM_SIZE] - 1],
			// result,
			// pos,
			// (pos + result) % MEM_SIZE);
			proc->pc = proc->pc + 6;
		}
		else
		{
			proc->pc = proc->pc + 5;
			return ;
		}
		place_in_arena(map, (pos + result) % MEM_SIZE, proc->reg[reg_nbr - 1]);
	}
	// printf("pc : %d\n", proc->pc);
}
