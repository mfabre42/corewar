/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:13:28 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/31 15:17:38 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (s1 && s2)
	{
		join = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (join == NULL)
			return (NULL);
		ft_strcat(join, s1);
		ft_strcat(join, s2);
		join[ft_strlen(join)] = '\0';
		return (join);
	}
	return (NULL);
}
