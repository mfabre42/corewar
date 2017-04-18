/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:06:58 by mafabre           #+#    #+#             */
/*   Updated: 2016/04/02 19:16:10 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s && f)
	{
		mapi = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (mapi == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			mapi[i] = f(j, s[i]);
			i++;
			j++;
		}
		mapi[i] = '\0';
		return (mapi);
	}
	return (NULL);
}
