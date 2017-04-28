/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:37:41 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/19 14:42:49 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_lenght(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*nbr;
	int		len;
	int		sign;

	len = ft_lenght(n);
	sign = (n < 0) ? -1 : 1;
	n = (n < 0) ? -n : n;
	nbr = (char *)malloc(sizeof(char) * len + 1);
	if (nbr == NULL)
		return (NULL);
	nbr[len--] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	while (n > 0)
	{
		nbr[len--] = n % 10 + '0';
		n = n / 10;
	}
	nbr[0] = (sign < 0) ? '-' : nbr[0];
	return (nbr);
}
