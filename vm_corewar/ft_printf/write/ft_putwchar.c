/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:37:50 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 17:40:11 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_puttwodigit(unsigned int carac)
{
	unsigned int	mask;
	unsigned char	o1;
	unsigned char	o2;

	mask = 49280;
	o1 = (carac << 26) >> 26;
	o2 = ((carac >> 6) << 27) >> 27;
	o2 = (mask >> 8) | o2;
	ft_putchar(o2);
	o1 = ((mask << 24) >> 24) | o1;
	ft_putchar(o1);
}

void	ft_putthreedigit(unsigned int carac)
{
	unsigned int	mask;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;

	mask = 14712960;
	o1 = (carac << 26) >> 26;
	o2 = ((carac >> 6) << 26) >> 26;
	o3 = ((carac >> 12) << 28) >> 28;
	o3 = (mask >> 16) | o3;
	ft_putchar(o3);
	o2 = ((mask << 16) >> 24) | o2;
	ft_putchar(o2);
	o1 = ((mask << 24) >> 24) | o1;
	ft_putchar(o1);
}

void	ft_putfourdigit(unsigned int carac)
{
	unsigned int	mask;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;

	mask = 4034953344;
	o1 = (carac << 11) >> 29;
	o2 = (carac << 14) >> 26;
	o3 = (carac << 20) >> 26;
	o4 = (carac << 26) >> 26;
	o1 = (mask >> 24) | o1;
	ft_putchar(o1);
	o2 = ((mask << 8) >> 24) | o2;
	ft_putchar(o2);
	o3 = ((mask << 16) >> 24) | o3;
	ft_putchar(o3);
	o4 = ((mask << 24) >> 24) | o4;
	ft_putchar(o4);
}

int		ft_putwchar(wchar_t c, int retu)
{
	unsigned int	carac;
	int				i;

	carac = c;
	i = ft_nbrlen_base(c, 2);
	if (i <= 7)
		ft_putchar(carac);
	else if (i <= 11)
	{
		ft_puttwodigit(carac);
		retu += 1;
	}
	else if (i <= 16)
	{
		ft_putthreedigit(carac);
		retu += 2;
	}
	else if (i <= 21)
	{
		ft_putfourdigit(carac);
		retu += 3;
	}
	retu++;
	return (retu);
}
