/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writestr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:08:05 by aleveque          #+#    #+#             */
/*   Updated: 2016/12/13 20:56:33 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	writestr(char *begin, char *end, int retu)
{
	int i;

	i = 0;
	if (begin <= end)
	{
		while (&begin[i] != end && begin[i])
		{
			ft_putchar(begin[i]);
			retu++;
			i++;
		}
	}
	return (retu);
}
