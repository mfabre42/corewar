/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:22:14 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/26 04:32:41 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	init_process(t_map *map, int player, int start)
{
	t_player	tmp;
	t_process	*proc;

	tmp = map->player[player];
	if ((proc = ft_lstnew(start, 1)) == NULL)
		error_malloc();
	proc->reg[0] = (unsigned int)player + 1;
	ft_lstadd(&tmp.process, proc);
	return (tmp);
}
