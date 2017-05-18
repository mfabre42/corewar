/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optn_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:59:11 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 17:31:45 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*optn_spacee(char *str, int nbr)
{
	int		len;
	int		i;
	char	*new;
	int		x;

	x = 0;
	i = -1;
	len = ft_strlen(str);
	if (len < nbr)
	{
		if (!(new = (char*)malloc(sizeof(char) * nbr + 1)))
			return (NULL);
		while (++i < nbr - len)
			new[i] = ' ';
		while (str[x])
			new[i++] = str[x++];
		new[i] = '\0';
		return (new);
	}
	return (str);
}

static int	ft_ispositive(char *str)
{
	int nbr;

	nbr = ft_atoi(str);
	if (nbr < 0)
		return (0);
	return (1);
}

static int	is_plus(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (str[i++] == '+')
			return (1);
	return (0);
}

char		*optn_plu(char *str, int nbr, int i, int x)
{
	int		len;
	char	*new;

	len = ft_strlen(str);
	if (ft_ispositive(str) == 1 && is_plus(str) != 1)
	{
		new = (char*)malloc(sizeof(char) * len + 2);
		new[i++] = '+';
		while (str[x])
			new[i++] = str[x++];
		new[i] = '\0';
		new = optn_spacee(new, nbr);
		free(str);
		return (new);
	}
	if (nbr > len + 1 && is_plus(str) != 1)
	{
		new = optn_spacee(str, nbr);
		free(str);
		return (new);
	}
	return (str);
}

char		*optn_plus(char *str, int nbr)
{
	return (optn_plu(str, nbr, 0, 0));
}
