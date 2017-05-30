/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:36:39 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 20:43:09 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_charwlen(wchar_t carac)
{
	int i;

	i = ft_nbrlen_base(carac, 2);
	if (i <= 7)
		return (1);
	else if (i <= 11)
		return (2);
	else if (i <= 16)
		return (3);
	else if (i <= 21)
		return (4);
	return (0);
}
