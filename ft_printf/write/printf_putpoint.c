/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_puthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:48:04 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 14:38:13 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*printf_putpoint(long long nbr)
{
	char	*ret;
	char	*str;
	int		i;

	i = -1;
	str = ft_itoa_base(nbr, 16);
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	if (!(ret = (char*)malloc(sizeof(char) * (i + 3))))
		return (NULL);
	ret[0] = '0';
	ret[1] = 'x';
	i = -1;
	while (str[++i])
		ret[i + 2] = str[i];
	ret[i + 2] = '\0';
	free(str);
	return (ret);
}
