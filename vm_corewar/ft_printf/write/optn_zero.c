/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optn_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:49:07 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 17:29:14 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_oct(char *str, int bol)
{
	int i;

	i = 0;
	while (str[i++])
	{
		if (str[i] == 'x')
		{
			bol = 1;
			str[i] = '0';
		}
		if (str[i] == 'X')
		{
			bol = 2;
			str[i] = '0';
		}
	}
	i = 0;
	while (str[i] != '0')
		i++;
	if (bol == 1)
		str[i + 1] = 'x';
	else if (bol == 2)
		str[i + 1] = 'X';
	return (str);
}

char	*ft_moins(char *new, char *str)
{
	int i;
	int bol;

	i = 0;
	bol = 0;
	while (new[i])
		if (new[i++] == '-')
			bol = 1;
	i = 0;
	if (bol == 1)
	{
		while (new[i] != '-' && new[i])
			i++;
		if (new[i] == '-')
			new[i] = '0';
		i = 0;
		while (new[i] != '0' && new[i])
			i++;
		if (new[i] == '0')
			new[i] = '-';
	}
	free(str);
	return (new);
}

char	*optn_zer(char *str, int nbr, int bol, int x)
{
	int		len;
	int		i;
	char	*new;

	i = -1;
	len = ft_strlen(str);
	while (str[++i])
		if (str[i] == 'x' || str[i] == 'X')
			bol = 1;
	i = -1;
	if (len < nbr)
	{
		if (!(new = (char*)malloc(sizeof(char) * nbr + 1)))
			return (NULL);
		while (++i < nbr - len)
			new[i] = '0';
		while (str[x])
			new[i++] = str[x++];
		new[i] = '\0';
		if (bol == 1)
			new = ft_oct(new, 0);
		ft_moins(new, str);
		return (new);
	}
	return (str);
}

char	*optn_zero(char *str, int nbr)
{
	return (optn_zer(str, nbr, 0, 0));
}
