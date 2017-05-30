/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:01:18 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 14:35:05 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

char	*ft_castjd(va_list ap)
{
	intmax_t content;

	content = va_arg(ap, intmax_t);
	if (content == LONG_MIN)
		return ("-9223372036854775808");
	return (ft_itoa_intmax(content, 10));
}

char	*ft_casthd(va_list ap)
{
	short content;

	content = va_arg(ap, int);
	return (ft_itoa_base((long long)content, 10));
}

char	*ft_casthhd(va_list ap)
{
	signed char content;

	content = va_arg(ap, int);
	return (ft_itoa_base((long long)content, 10));
}

char	*ft_castld(va_list ap)
{
	long content;

	content = va_arg(ap, long);
	if (content == LONG_MIN)
		return ("-9223372036854775808");
	return (ft_itoa_base((long long)content, 10));
}

char	*ft_castlld(va_list ap)
{
	long long content;

	content = va_arg(ap, long long);
	if (content == LONG_MIN)
		return ("-9223372036854775808");
	return (ft_itoa_intmax(content, 10));
}
