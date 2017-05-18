/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optn_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:58:30 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 14:02:32 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*optn_point(char *str, int i)
{
	int		x;
	char	*new;

	x = 0;
	if (ft_strlen(str) > i)
	{
		if (!(new = (char*)malloc(sizeof(char) * i + 1)))
			return (NULL);
		while (x < i)
		{
			new[x] = str[x];
			x++;
		}
		new[x] = '\0';
		free(str);
		return (new);
	}
	return (str);
}
