/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:53:14 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/01 18:54:30 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	func_and3(t_map *map, t_process *proc, t_bin *bin, int *param1)
{
	if (OCP.param2 == 'R')
	{
		if (!is_reg((int)ARENA[(POS + PC) % MEM_SIZE], proc, PC + 1))
			return (0);
		*param1 = *param1 & proc->reg[(int)ARENA[(POS + PC) % MEM_SIZE] - 1];
		PC += 1;
	}
	else if (OCP.param2 == 'I')
	{
		*param1 = *param1 & read_in_arena(map, POS + (short)hex_to_int(0x00,
			0x00, ARENA[(POS + PC) % MEM_SIZE],
			ARENA[(POS + PC + 1) % MEM_SIZE]) % IDX_MOD);
		PC += 2;
	}
	else if (OCP.param2 == 'D')
	{
		*param1 = *param1 & hex_to_int(ARENA[(POS + PC) % MEM_SIZE],
			ARENA[(POS + PC + 1) % MEM_SIZE], ARENA[(POS + PC + 2) % MEM_SIZE],
			ARENA[(POS + PC + 3) % MEM_SIZE]);
		PC += 4;
	}
	return (1);
}

static int	func_and2(t_map *map, t_process *proc, t_bin *bin, int *param1)
{
	if (OCP.param1 == 'R')
	{
		if (!is_reg((int)ARENA[(POS + PC) % MEM_SIZE], proc, 3))
			return (0);
		*param1 = proc->reg[(int)ARENA[(POS + PC) % MEM_SIZE] - 1];
		PC += 1;
	}
	else if (OCP.param1 == 'I')
	{
		*param1 = read_in_arena(map, POS + (short)hex_to_int(0x00, 0x00,
			ARENA[(POS + 2) % MEM_SIZE],
			ARENA[(POS + 3) % MEM_SIZE]) % IDX_MOD);
		PC += 2;
	}
	else if (OCP.param1 == 'D')
	{
		*param1 = hex_to_int(ARENA[(POS + 2) % MEM_SIZE],
		ARENA[(POS + 3) % MEM_SIZE], ARENA[(POS + 4)
		% MEM_SIZE], ARENA[(POS + 5) % MEM_SIZE]);
		PC += 4;
	}
	return (1);
}

void		func_and(t_map *map, t_process *proc)
{
	t_bin	bin;
	int		param1;

	if (proc->do_funk == 1)
		do_funk(proc, 4, 6, 0);
	else
	{
		do_funk(proc, 0, 0, 1);
		bin = init_bin(map, proc);
		if (func_and2(map, proc, &bin, &param1) == 0)
			return ;
		if (func_and3(map, proc, &bin, &param1) == 0)
			return ;
		if (!is_reg((int)ARENA[(PPOS + PPC) % MEM_SIZE], proc, PPC + 1))
			return ;
		if ((POCP.param1 == 'R' || POCP.param1 == 'I' || POCP.param1 == 'D') &&
			(POCP.param2 == 'R' || POCP.param2 == 'I' || POCP.param2 == 'D'))
		{
			proc->reg[(int)ARENA[(PPOS + PPC) % MEM_SIZE] - 1] = param1;
			proc->pc += PPC + 1;
			proc->carry = !param1;
		}
		else
			proc->pc = proc->pc + 5;
	}
}
