/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:34:09 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/12 23:24:13 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	direct_store(t_map *map, t_process *proc)
{
	int		reg_nbr;
	int		pos;
	int		result;
	t_ocp	ocp;


	if (proc->do_funk == 1)
	{
		do_funk(proc, 3, 3, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[(pos + 1) % MEM_SIZE]);
		reg_nbr = (int)map->arena[(pos + 2) % MEM_SIZE];
		if (!is_register(reg_nbr))
		{
			fail_func(proc, 4, 0);
			return ;
		}
		if (ocp.param2 == 'R')
		{
			if (!is_register(hex_to_int(0x00, 0x00, 0x00, map->arena[(pos + 3) % MEM_SIZE])))
			{
				fail_func(proc, 4, 0);
				return ;
			}
			proc->reg[(int)map->arena[(pos + 3) % MEM_SIZE] - 1] =  proc->reg[reg_nbr - 1];
			proc->pc = proc->pc + 4;

		}
		else
		{
			//Soit pos soit proc->pc
			result = (proc->pc + hex_to_int(0x00, 0x00,map->arena[(pos + 3) % MEM_SIZE], map->arena[(pos + 4) % MEM_SIZE])) % MEM_SIZE;
			printf("emplacement d'arene : %x %x %x %x %x, Pos: %d, Valeur du registre: %d, ocp.param2: %c, a l'adresse: %d + %d = %d, au tour: %d\n",
			map->arena[(pos) % MEM_SIZE],
			map->arena[(pos + 1) % MEM_SIZE],
			map->arena[(pos + 2) % MEM_SIZE],
			map->arena[(pos + 3) % MEM_SIZE],
			map->arena[(pos + 4) % MEM_SIZE],
			pos,
			proc->reg[reg_nbr - 1],
			ocp.param2,
			proc->pc,
			hex_to_int(0x00, 0x00,map->arena[(pos + 3) % MEM_SIZE], map->arena[(pos + 4) % MEM_SIZE]),
			result % MEM_SIZE,
			map->cycle);
			place_in_arena(map, result % MEM_SIZE, proc->reg[reg_nbr - 1]);
			proc->pc = proc->pc + 5;
		}
	}
}
