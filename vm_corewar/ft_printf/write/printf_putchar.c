/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:53:30 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 18:21:31 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_write_char(char *c, char carac)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '9')
			write(1, &carac, 1);
		else
			write(1, &c[i], 1);
		i++;
	}
	free(c);
	return (ft_itoa_base(i, 10));
}

char	*printf_putchar(long long carac, char *str)
{
	char	*c;
	int		i;

	i = ft_findconv(str);
	c = ft_strdup("9");
	i--;
	while (str[i] != '%')
	{
		while (str[i] >= '0' && str[i] <= '9')
			i--;
		if (str[i] == '-')
			c = optn_minus(c, ft_atoi(&str[i + 1]));
		if ((str[i] == '%' || str[i] == '#') && str[i + 1] >= '0'
				&& str[i + 1] <= '9')
			c = optn_nbr(c, ft_atoi(&str[i + 1]));
		if (str[i] != '%')
			i--;
	}
	c = ft_write_char(c, carac);
	return (c);
}
