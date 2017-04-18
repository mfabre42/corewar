/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 23:39:19 by mafabre           #+#    #+#             */
/*   Updated: 2016/09/30 23:21:55 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int nbr;
	int negative;

	negative = 0;
	nbr = 0;
	while (*nptr == 8 || *nptr == 9 || *nptr == 10 || *nptr == 11 ||
			*nptr == 12 || *nptr == 13 || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			negative = 1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + *nptr - '0';
		nptr++;
	}
	if (negative == 1)
		return (-nbr);
	return (nbr);
}
