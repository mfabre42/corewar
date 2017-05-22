/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:03:14 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/22 22:45:12 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*zero;

	i = 0;
	zero = (unsigned char *)s;
	while (i < n)
	{
		zero[i] = 0;
		i++;
	}
}
