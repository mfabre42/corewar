/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:19:37 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/04 20:08:52 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fork(t_map *map, t_process *proc, int player)
{
	int		pos;
	int		dest;

	if (proc->do_funk == 1)
	{
		proc->cycle = 799;
		proc->do_funk = 0;
	}
	else
	{
		proc->do_funk = 1;
		pos = proc->start + proc->pc;
		dest = pos + (hex_to_int(0x00, 0x00, map->arena[pos + 1],
			map->arena[pos + 2]) % IDX_MOD);
		cp_process(map, proc, player, dest);
		proc->pc = proc->pc + 3;
	}
}
