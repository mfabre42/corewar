/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convint3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:35:33 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/09 15:54:26 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

char	*ft_casthho(va_list ap, char c)
{
	signed char content;

	content = va_arg(ap, int);
	if (c == 'o')
		return (printf_putoct(content));
	if (c == 'x')
		return (printf_puthex(content));
	if (c == 'X')
		return (printf_puthexa(content));
	return (NULL);
}

char	*ft_castho(va_list ap, char c)
{
	short content;

	content = va_arg(ap, int);
	if (c == 'o')
		return (printf_putoct(content));
	if (c == 'x')
		return (printf_puthex(content));
	if (c == 'X')
		return (printf_puthexa(content));
	return (NULL);
}

char	*ft_castjo(va_list ap, char c)
{
	intmax_t content;

	content = va_arg(ap, intmax_t);
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

char	*ft_castzo(va_list ap, char c)
{
	size_t content;

	content = va_arg(ap, size_t);
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

char	*ft_casto(va_list ap, char c)
{
	long content;

	content = va_arg(ap, long);
	content = content % 4294967296;
	if (content == UINT_MAX && c == 'x')
		return (ft_strdup("ffffffff"));
	if (content == UINT_MAX && c == 'X')
		return (ft_strdup("FFFFFFFF"));
	if (c == 'o')
		return (printf_putoct(content));
	if (c == 'x')
		return (printf_puthex(content));
	if (c == 'X')
		return (printf_puthexa(content));
	return (NULL);
}
