/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:58:53 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 19:46:33 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*ret;

	i = 0;
	y = 0;
	if (!(s1 && s2))
		return (NULL);
	while (s1[i])
		i++;
	while (s2[y])
		y++;
	if (!(ret = (char*)malloc(sizeof(char) * (i + y + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	y = -1;
	while (s2[++y])
		ret[i + y] = s2[y];
	ret[i + y] = '\0';
	return (ret);
}
