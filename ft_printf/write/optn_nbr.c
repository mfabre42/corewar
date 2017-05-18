/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optn_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:14:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 17:51:25 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*optn_nbr(char *str, int nbr)
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
		free(str);
		return (new);
	}
	return (str);
}
