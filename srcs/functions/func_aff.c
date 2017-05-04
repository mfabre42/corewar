/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:43:55 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/04 16:09:58 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	aff_char(t_map *map, t_process *proc)
{
	int		pos;
	int		result;
	t_ocp	ocp;

	if (proc->do_funk == 1)
	{
		proc->cycle = 2;
		proc->do_funk = 0;
	}
	else
	{
		proc->do_funk = 1;
		pos = proc->start + proc->pc;
		ocp = ocp_master((int)map->arena[pos + 1]);
		if (ocp.param1 == 'R')
		{
			if (!is_register((int)map->arena[pos + 2]))
			{
				printf("crash process a gerer"); //LOL
				exit(0);
			}
			ft_putchar((proc->reg[(int)map->arena[pos + 2] - 1]) % 256);
		}
		proc->pc = proc->pc + 3;
	}
}
