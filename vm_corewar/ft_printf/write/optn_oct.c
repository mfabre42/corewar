/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optn_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:56:17 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 17:07:26 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*optn_octal(char *ret, int len1, int len2)
{
	char	*str;
	int		i;

	i = -1;
	if (len1 > len2)
	{
		i++;
		while (ret[i] == ' ')
			i++;
		if (i >= 1)
			ret[i - 1] = '0';
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * (len1 + 2))))
			return (NULL);
		str[0] = '0';
		while (ret[++i])
			str[i + 1] = ret[i];
		str[i + 1] = '\0';
		return (str);
	}
	return (ret);
}

char	*hexa(char *ret, char *str, int x, int len)
{
	x++;
	while (ret[x] == ' ')
		x++;
	if (x >= 2)
	{
		ret[x - 2] = '0';
		ret[x - 1] = 'x';
		if (str[ft_findconv(str)] == 'X')
			ret[x - 1] = 'X';
	}
	else
	{
		ret[0] = '0';
		ret[1] = 'x';
		if (str[ft_findconv(str)] == 'X')
			ret[1] = 'X';
	}
	return (ret);
}

char	*hexoct(char *ret, char *str, int len, char *new)
{
	int x;

	x = -1;
	if (ft_strlen(ret) > len + 1)
		return (hexa(ret, str, x, len));
	else
	{
		new = (char*)malloc(sizeof(char) * (ft_strlen(ret) + 2));
		new[0] = '0';
		new[1] = 'x';
		if (str[ft_findconv(str)] == 'X')
			new[1] = 'X';
		while (ret[++x])
			new[x + 2] = ret[x];
	}
	free(ret);
	return (new);
}

char	*optn_oct(char *ret, char *str)
{
	char	*new;
	int		x;
	int		len;

	x = -1;
	if (ret[0] == '0')
		return (ret);
	len = ft_strlen(ret);
	if (ret != 0)
	{
		if (str[ft_findconv(str)] == 'o' || str[ft_findconv(str)] == 'O')
		{
			ret = optn_octal(ret, ft_strlen(ret), len);
			return (ret);
		}
		else if (str[ft_findconv(str)] == 'x' || str[ft_findconv(str)] == 'X')
		{
			return (hexoct(ret, str, len, new));
		}
	}
	return (ret);
}
