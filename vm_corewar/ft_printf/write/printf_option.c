/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:32:42 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 20:26:39 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_init(char *(**tabf)(char*, int))
{
	tabf[1] = &optn_plus;
	tabf[2] = &optn_minus;
}

int		shure(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (2);
	return (0);
}

char	*option(char *str, char *ret, char *(**tabf)(char*, int), int i)
{
	int bol;

	while (str[i] != '%')
	{
		bol = 0;
		if (str[i] >= '0' && str[i] <= '9')
		{
			bol = 1;
			while (str[i] >= '0' && str[i] <= '9')
				i--;
		}
		if (shure(str[i]) > 0 && shure(str[i]) <= 3)
			ret = tabf[shure(str[i])](ret, ft_atoi(&str[1 + i]));
		else if (str[i] == '.')
			ret = optn_zero(ret, ft_atoi(&str[i + 1]));
		else if (str[i + 1] == '0')
			ret = optn_zero(ret, ft_atoi(&str[i + 1]));
		else if ((str[i] == '%' || str[i] == '#') && bol == 1)
			ret = optn_nbr(ret, ft_atoi(&str[i + 1]));
		if (str[i] != '%')
			i--;
	}
	return (ret);
}

char	*optn(char *str, char *ret, int i, int bol)
{
	char	*(*tabf[6])(char*, int);

	ret = ft_free(ret, str);
	ft_init(tabf);
	bol = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		bol = 1;
		while (str[i] >= '0' && str[i] <= '9')
			i--;
	}
	if (shure(str[i]) > 0 && shure(str[i]) <= 2)
		ret = tabf[shure(str[i])](ret, ft_atoi(&str[1 + i]));
	else if (str[i] == '.')
	{
		if (str[ft_findconv(str)] == 's')
			ret = optn_point(ret, ft_atoi(&str[i + 1]));
		else if (str[ft_findconv(str) != 'c'])
			ret = optn_zero(ret, ft_atoi(&str[i + 1]));
	}
	else if (str[i + 1] == '0')
		ret = optn_zero(ret, ft_atoi(&str[i + 1]));
	else if ((str[i] == '%' || str[i] == '#') && bol == 1)
		ret = optn_nbr(ret, ft_atoi(&str[i + 1]));
	return (ret);
}

char	*printf_option(char *str, char *ret)
{
	int		i;
	int		bol;
	char	*(*tabf[6])(char*, int);

	ft_init(tabf);
	bol = 0;
	i = ft_findconv(str);
	if (str[i] == '%')
		return (option(str, ret, tabf, ft_findconv(str) - 1));
	while (str[--i] != '%' && bol == 0)
		if (str[i] == '#')
			bol = 1;
	if (bol == 1)
		ret = optn_oct(ret, str);
	i = ft_findconv(str);
	while (str[i--] != '%')
	{
		ret = optn(str, ret, i, bol);
	}
	i = ft_findconv(str);
	while (str[i--] != '%')
		if (str[i] == ' ')
			ret = optn_space(ret, ft_atoi(&str[i + 1]));
	return (ret);
}
