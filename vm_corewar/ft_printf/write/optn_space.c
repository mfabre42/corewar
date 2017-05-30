/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optn_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:57:15 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 17:20:21 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*optn_espace(char *str, int nbr)
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

char		*space(char *str, int nbr, int x, int i)
{
	int		len;
	char	*new;

	while (str[i])
		if (str[i++] == '+' && nbr < ft_strlen(str))
			return (str);
	i = 0;
	len = ft_strlen(str);
	if (ft_ispositive(str) == 1)
	{
		new = (char*)malloc(sizeof(char) * len + 2);
		new[i++] = ' ';
		while (str[x])
			new[i++] = str[x++];
		new[i] = '\0';
		new = optn_espace(new, nbr);
	}
	if (nbr > len + 1)
		new = optn_espace(str, nbr);
	if (ft_ispositive(str) == 1 || nbr > (len + 1))
		free(str);
	if (ft_ispositive(str) == 1 || nbr > (len + 1))
		return (new);
	return (str);
}

char		*optn_space(char *str, int nbr)
{
	return (space(str, nbr, 0, 0));
}
