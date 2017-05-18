/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:33:33 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 17:01:14 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_printf(char *s, int retu, char *str)
{
	int i;

	i = 0;
	if (s[0] == 0 && str[ft_findconv(str)] == 'c')
	{
		ft_putchar(s[0]);
		return (retu + 1);
	}
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
			retu++;
		}
		free(s);
	}
	return (retu);
}
