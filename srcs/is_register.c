/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_register.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 22:11:57 by acoupleu          #+#    #+#             */
/*   Updated: 2017/05/02 12:26:18 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

int	is_register(unsigned int reg)
{
	if (reg >= 1 && reg <= REG_NUMBER)
		return (1);
	return (0);
}