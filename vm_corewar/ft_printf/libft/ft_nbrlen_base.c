/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:13:38 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 20:43:26 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_nbrlen_base(long long nbr, int base)
{
	unsigned long long	nb;
	int					i;

	i = 1;
	if (nbr < 0 && base == 10)
	{
		nbr = -nbr;
		i++;
	}
	nb = (unsigned long long)nbr;
	while (nb >= base)
	{
		nb /= base;
		i++;
	}
	return (i);
}
