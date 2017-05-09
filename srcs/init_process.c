/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:22:14 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/09 17:19:48 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	init_process(t_map *map, int player, int start)
{
	t_player	tmp;
	t_process	*proc;

	printf("player : %d\n", player);//ici aussi
	tmp = map->player[player];
	proc = ft_lstnew(start);
	proc->reg[0] = (unsigned int)player + 1;
	printf("start : %d\n", proc->start);
	ft_lstadd(&tmp.process, proc);
	return (tmp);
}
