/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:28:45 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/23 18:34:13 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cp_process(t_map *map, t_process *proc, int player, int adress)
{
	t_process	*new_proc;
	int			i;

	i = 0;
	new_proc = ft_lstnew(adress, map->cycle);
	while (i < 16)
	{
		new_proc->reg[i] = proc->reg[i];
		i++;
	}
	new_proc->carry = proc->carry;
	ft_lstadd(&map->player[player].process, new_proc);
}
