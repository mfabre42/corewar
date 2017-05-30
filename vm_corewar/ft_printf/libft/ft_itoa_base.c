/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:44:03 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/09 15:55:49 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <inttypes.h>

char		*ft_itoa_base(long long nbr, int base)
{
	unsigned long long	nb;
	char				*cnbr;
	int					i;
	int					ret;
	static char			chbase[16] = {'0', '1', '2', '3', '4', '5', '6',
		'7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	i = ft_nbrlen_base(nbr, base);
	if (!(cnbr = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (nbr < 0 && base == 10)
	{
		cnbr[0] = '-';
		nbr = -nbr;
	}
	nb = (unsigned long long)nbr;
	cnbr[i--] = '\0';
	while (nb > base - 1)
	{
		ret = (nb % base);
		cnbr[i--] = chbase[ret];
		nb /= base;
	}
	cnbr[i] = chbase[nb];
	return (cnbr);
}
