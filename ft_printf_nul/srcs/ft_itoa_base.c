/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:00:45 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/25 17:17:13 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenght_int(unsigned long long n, int base)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(unsigned long long n, int base)
{
	char	*str;
	int		i;

	i = lenght_int(n, base);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		if ((n % base) >= 10)
			str[i] = (n % base) - 10 + 'a';
		else
			str[i] = (n % base) + '0';
		n = n / base;
		i--;
	}
	return (str);
}
