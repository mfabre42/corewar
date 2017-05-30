/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:00:08 by aleveque          #+#    #+#             */
/*   Updated: 2016/12/02 13:30:30 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_aff(char *str, int i, int neg)
{
	int ret;

	ret = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret * neg);
}

int			ft_atoi(char *str)
{
	int i;
	int neg;

	i = 0;
	neg = 1;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' ||
		str[i] == ' ' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	return (ft_aff(str, i, neg));
}
