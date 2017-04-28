/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:24:20 by mafabre           #+#    #+#             */
/*   Updated: 2016/03/21 18:20:22 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sch;

	i = 0;
	sch = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == sch[i])
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
