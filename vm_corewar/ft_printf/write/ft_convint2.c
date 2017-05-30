/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convint2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:11:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/09 15:36:53 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

char	*ft_castzd(va_list ap)
{
	size_t content;

	content = va_arg(ap, size_t);
	if (content == LONG_MIN)
		return ("-9223372036854775808");
	return (ft_itoa_base((long long)content, 10));
}

char	*ft_castd(va_list ap)
{
	int content;

	content = va_arg(ap, int);
	return (ft_itoa_base((long long)content, 10));
}

char	*ft_castp(va_list ap)
{
	unsigned long content;

	content = va_arg(ap, unsigned long);
	if (content == LONG_MIN)
		return ("0x8000000000000000");
	return (printf_putpoint(content));
}

char	*ft_castllo(va_list ap, char c)
{
	long long content;

	content = va_arg(ap, long long);
	if (content == LONG_MIN)
		return ("-9223372036854775808");
	if (content == ULLONG_MAX && c == 'o')
		return (ft_strdup("1777777777777777777777"));
	if (content == ULLONG_MAX && c == 'x')
		return (ft_strdup("ffffffffffffffff"));
	if (content == ULLONG_MAX && c == 'X')
		return (ft_strdup("FFFFFFFFFFFFFFFF"));
	if (c == 'o')
		return (printf_putoct(content));
	if (c == 'x')
		return (printf_puthex(content));
	if (c == 'X')
		return (printf_puthexa(content));
	return (NULL);
}

char	*ft_castlo(va_list ap, char c)
{
	long content;

	content = va_arg(ap, long);
	if (content == LONG_MIN)
		return ("-9223372036854775808");
	if (content == ULONG_MAX && c == 'o')
		return (ft_strdup("1777777777777777777777"));
	if (content == ULONG_MAX && c == 'x')
		return (ft_strdup("ffffffffffffffff"));
	if (content == ULONG_MAX && c == 'X')
		return (ft_strdup("FFFFFFFFFFFFFFFF"));
	if (c == 'o' || c == 'O')
		return (printf_putoct(content));
	if (c == 'x')
		return (printf_puthex(content));
	if (c == 'X')
		return (printf_puthexa(content));
	return (NULL);
}
