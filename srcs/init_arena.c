/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 20:49:40 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/26 21:02:31 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

t_convert	create_arena(void)
{
	t_convert	arena;

	arena = (t_convert *)malloc(sizeof(t_convert) * MEM_SIZE);
}
