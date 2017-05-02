/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:41:08 by acoupleu          #+#    #+#             */
/*   Updated: 2017/04/27 21:50:19 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	hex_to_int(unsigned char a, unsigned char b,
					unsigned char c, unsigned char d)
{
	t_convert	converse;

	converse.c_char[0] = d;
	converse.c_char[1] = c;
	converse.c_char[2] = b;
	converse.c_char[3] = a;
	return (converse.c_int);
}
