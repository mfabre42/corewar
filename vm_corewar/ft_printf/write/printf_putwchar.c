/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putwchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:38:45 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 20:13:03 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_write_wchar(char *c, wchar_t carac)
{
	int i;
	int retu;

	retu = 0;
	i = 0;
	while (c[i])
	{
		if (c[i] == '9')
		{
			retu = ft_putwchar(carac, retu);
			while (c[i] == '9')
				i++;
		}
		else
		{
			write(1, &c[i], 1);
			retu++;
			i++;
		}
	}
	free(c);
	return (ft_itoa_base(retu, 10));
}

static char	*init_c(char *c, int i)
{
	if (i == 1)
		c = ft_strdup("9");
	if (i == 2)
		c = ft_strdup("99");
	if (i == 3)
		c = ft_strdup("999");
	if (i == 4)
		c = ft_strdup("9999");
	return (c);
}

static int	ft_searchconv(char *str)
{
	int i;

	i = 0;
	while (str[i] != 'c' && str[i] != 'C')
		i++;
	return (i);
}

char		*printf_putwchar(wchar_t carac, char *str)
{
	char	*c;
	int		i;

	i = ft_searchconv(str);
	c = init_c(c, ft_charwlen(carac));
	i--;
	while (str[i] != '%')
	{
		while (str[i] >= '0' && str[i] <= '9' && str[i])
			i--;
		if (str[i] == '-')
			c = optn_minus(c, ft_atoi(&str[i + 1]));
		if ((str[i] == '%' || str[i] == '#') && str[i + 1] >= '0'
				&& str[i + 1] <= '9')
			c = optn_nbr(c, ft_atoi(&str[i + 1]));
		if (str[i] != '%')
			i--;
	}
	c = ft_write_wchar(c, carac);
	return (c);
}
