/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:09:39 by mafabre           #+#    #+#             */
/*   Updated: 2016/03/23 21:53:10 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	source;
	size_t	destination;

	i = 0;
	source = ft_strlen(src);
	destination = ft_strlen(dst);
	if (size > destination + 1)
	{
		while (i < (size - destination - 1))
		{
			dst[i + destination] = src[i];
			i++;
		}
		dst[destination + i] = '\0';
	}
	if (size >= destination)
		return (destination + source);
	return (source + size);
}
