/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:34:30 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 15:14:43 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	if (str1[0] == '\0' && str2[0] == '\0')
		return (0);
	while (str1[i] == str2[i] && (str1[i] && str2[i]))
		i++;
	return (((unsigned char)str1[i] - (unsigned char)str2[i]));
}
