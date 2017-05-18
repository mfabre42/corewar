/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:19:03 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 14:27:17 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdint.h>

int		ft_nbrlenmax(intmax_t nbr, int base)
{
	int i;

	i = 1;
	if (nbr <= -1)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_intmax(intmax_t nbr, int base)
{
	char		*cnbr;
	int			i;
	static char	chbase[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	i = ft_nbrlenmax(nbr, base);
	if (!(cnbr = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (nbr < 0)
	{
		cnbr[0] = '-';
		nbr = -nbr;
	}
	cnbr[i--] = '\0';
	while (nbr > base - 1)
	{
		cnbr[i] = chbase[nbr % base];
		nbr /= base;
		i--;
	}
	cnbr[i] = chbase[nbr];
	return (cnbr);
}

char	*ft_itoa_llu(uintmax_t nbr)
{
	char		*ret;
	int			i;
	uintmax_t	n;

	i = 1;
	n = nbr;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i] = '\0';
	i--;
	while (nbr > 9)
	{
		ret[i] = (nbr % 10 + 48);
		nbr /= 10;
		i--;
	}
	ret[0] = nbr + 48;
	return (ret);
}
