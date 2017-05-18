/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:38:01 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 21:03:43 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_write_wstr(char *c, wchar_t *str, int i, int retu)
{
	int x;

	x = 0;
	while (c[i])
	{
		if (c[i] == '1')
			i++;
		if (c[i] == '9')
		{
			retu = ft_putwchar(str[x], retu);
			i += ft_charwlen(str[x]);
			x++;
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

static char	*init_c(char *c, wchar_t *str)
{
	int		i;
	int		y;
	char	*tmp;

	i = 0;
	c = ft_strdup("");
	while (str[i])
	{
		tmp = c;
		y = ft_charwlen(str[i]);
		if (y == 1)
			c = ft_strjoin(c, "9");
		if (y == 2)
			c = ft_strjoin(c, "99");
		if (y == 3)
			c = ft_strjoin(c, "999");
		if (y == 4)
			c = ft_strjoin(c, "9999");
		free(tmp);
		i++;
	}
	return (c);
}

static int	ft_search_conv(char *str)
{
	int i;

	i = 0;
	while (str[i] != 's' && str[i] != 'S')
		i++;
	return (i);
}

char		*ft_putwstr(wchar_t *s, char *str)
{
	char	*c;
	int		i;

	c = init_c(c, s);
	i = ft_search_conv(str);
	i--;
	while (str[i] != '%')
	{
		while (str[i] >= '0' && str[i] <= '9')
			i--;
		if (str[i] == '-')
			c = optn_minus(c, ft_atoi(&str[i + 1]));
		if (str[i] == '.')
			c = optn_point(c, ft_atoi(&str[i + 1]));
		if ((str[i] == '%' || str[i] == '#') && str[i + 1] >= '0'
				&& str[i + 1] <= '9')
			c = optn_nbr(c, ft_atoi(&str[i + 1]));
		if (str[i] != '%')
			i--;
	}
	c = ft_write_wstr(c, s, 0, 0);
	return (c);
}
