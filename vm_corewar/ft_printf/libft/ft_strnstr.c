/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:16:09 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 14:52:02 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(char *big, char *little, size_t len)
{
	unsigned int i;
	unsigned int x;

	i = 0;
	if (little[0] == '\0')
		return (big);
	while (big[i] && i < len)
	{
		x = 0;
		if (big[i] == little[x])
		{
			while (little[x] == big[i + x] && little[x] && (i + x) < len)
				x++;
			if (little[x] == '\0')
				return (&big[i]);
		}
		i++;
	}
	return (NULL);
}
