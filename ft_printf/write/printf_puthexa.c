/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_puthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:48:04 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 14:40:04 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*printf_puthexa(long long nbr)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_itoa_base(nbr, 16);
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	return (str);
}
