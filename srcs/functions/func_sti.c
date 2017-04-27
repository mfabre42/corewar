/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:15:10 by acoupleu          #+#    #+#             */
/*   Updated: 2017/04/27 22:18:49 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	indirect_store(t_map *map, t_player *player)
{
	int		reg;
	int		pos;
	int		result;
	t_ocp	ocp;

	pos = player->start + player->pc;
	ocp = ocp_master((int)map->arena[pos + 1]);
	reg = (int)map->arena[pos + 2];
	if (ocp.param2 == 'R')
	{
		if (!is_register(hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 3])))
		{
			printf("crash");
			exit(0);
		}
		result += (int)map->arena[pos + 4];
		result += (int)map->arena[pos + 5];
	}
	1 2 2


}
