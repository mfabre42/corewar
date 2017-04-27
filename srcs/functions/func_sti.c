/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:15:10 by acoupleu          #+#    #+#             */
/*   Updated: 2017/04/27 23:31:11 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	indirect_store(t_map *map, t_player *player)
{
	int		reg_nbr;
	int		pos;
	int		result;
	t_ocp	ocp;

	pos = player->start + player->pc;
	ocp = ocp_master((int)map->arena[pos + 1]);
	reg_nbr = (int)map->arena[pos + 2];
	if (ocp.param2 == 'R')
	{
		if (!is_register(hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 3])))
		{
			printf("crash process a gerer"); //LOL
			exit(0);
		}
		i = 0;
		result = player->reg[hex_to_int(0x00, 0x00, 0x00, map->arena[pos + 3])]
		result += hex_to_int(0x00, 0x00, map->arena[pos + 4],
			map->arena[pos + 5]);
		player->pc = player->pc + 6;
	}
	else
	{
		result = hex_to_int(0x00, 0x00, map->arena[pos + 3], map->arena[pos + 4]);
		result += hex_to_int(0x00, 0x00, map->arena[pos + 5], map->arena[pos + 6]);
		player->pc = player->pc + 7;
	}
	place_in_arena(map, pos + (result % IDX_MOD), player->reg[reg_nbr]);
}
