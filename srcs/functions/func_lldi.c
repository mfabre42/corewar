/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_lldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:42:36 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/24 02:06:05 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	lindirect_load3(t_map *map, t_process *proc, t_bin *bin, int *result)
{
	if ((OCP.param1 == 'D' || OCP.param1 == 'I') && OCP.param2 == 'R')
	{
		if (!is_reg((int)ARENA[(POS + 4) % MEM_SIZE], proc, 6)
		|| !is_reg((int)ARENA[(POS + 5) % MEM_SIZE], proc, 6))
			return (0);
		*result = (short)hex_to_int(0x00, 0x00, ARENA[(POS + 2) % MEM_SIZE],
		ARENA[(POS + 3) % MEM_SIZE]);
		*result += proc->reg[(int)ARENA[(POS + 4) % MEM_SIZE] - 1];
		proc->reg[(int)ARENA[(POS + 5) % MEM_SIZE] - 1] =
		read_in_arena(map, (POS + *result) % MEM_SIZE);
		proc->pc = proc->pc + 6;
	}
	else if ((OCP.param1 == 'D' || OCP.param1 == 'I') && OCP.param2 == 'D')
	{
		if (!is_reg((int)ARENA[(POS + 6) % MEM_SIZE], proc, 7))
			return (0);
		*result = (short)hex_to_int(0x00, 0x00, ARENA[(POS + 2) % MEM_SIZE],
		ARENA[(POS + 3) % MEM_SIZE]);
		*result += (short)hex_to_int(0x00, 0x00, ARENA[(POS + 4) % MEM_SIZE],
		ARENA[(POS + 5) % MEM_SIZE]);
		proc->reg[(int)ARENA[(POS + 6) % MEM_SIZE] - 1] =
		read_in_arena(map, (POS + *result) % MEM_SIZE);
		proc->pc = proc->pc + 7;
	}
	return (1);
}

static int	lindirect_load2(t_map *map, t_process *proc, t_bin *bin, int *result)
{
	if (OCP.param1 == 'R' && OCP.param2 == 'R')
	{
		if (!is_reg((int)ARENA[(POS + 2) % MEM_SIZE], proc, 5)
		|| !is_reg((int)ARENA[(POS + 3) % MEM_SIZE], proc, 5)
		|| !is_reg((int)ARENA[(POS + 4) % MEM_SIZE], proc, 5))
			return (0);
		*result = proc->reg[(int)ARENA[(POS + 2) % MEM_SIZE] - 1];
		*result += proc->reg[(int)ARENA[(POS + 3) % MEM_SIZE] - 1];
		proc->reg[(int)ARENA[(POS + 4) % MEM_SIZE] - 1] =
		read_in_arena(map, (POS + *result) % MEM_SIZE);
		proc->pc = proc->pc + 5;
	}
	else if (OCP.param1 == 'R' && OCP.param2 == 'D')
	{
		if (!is_reg((int)ARENA[(POS + 2) % MEM_SIZE], proc, 6)
		|| !is_reg((int)ARENA[(POS + 5) % MEM_SIZE], proc, 6))
			return (0);
		*result = proc->reg[(int)ARENA[(POS + 2) % MEM_SIZE] - 1];
		*result += (short)hex_to_int(0x00, 0x00, ARENA[(POS + 3) % MEM_SIZE],
		ARENA[(POS + 4) % MEM_SIZE]);
		proc->reg[(int)ARENA[(POS + 5) % MEM_SIZE] - 1] =
		read_in_arena(map, (POS + *result) % MEM_SIZE);
		proc->pc = proc->pc + 6;
	}
	return (1);
}

void		lindirect_load(t_map *map, t_process *proc)
{
	t_bin	bin;
	int		result;

	if (proc->do_funk == 1)
	{
		do_funk(proc, 23, 14, 0);
	}
	else
	{
		do_funk(proc, 0, 0, 1);
		bin = init_bin(map, proc);
		if (POCP.param1 == 'R' && (POCP.param2 == 'R' || POCP.param2 == 'D'))
		{
			if (lindirect_load2(map, proc, &bin, &result) == 0)
				return ;
		}
		else if ((POCP.param1 == 'D' || POCP.param1 == 'I')
				&& (POCP.param2 == 'R' || POCP.param2 == 'D'))
		{
			if (lindirect_load3(map, proc, &bin, &result) == 0)
				return ;
		}
	}
}
