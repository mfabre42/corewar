/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:58:42 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 19:09:38 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_castzu(va_list ap)
{
	size_t content;

	content = va_arg(ap, size_t);
	return (ft_itoa_llu(content));
}

char	*ft_castls(va_list ap, char *str)
{
	wchar_t *content;

	content = va_arg(ap, wchar_t*);
	if (content == NULL)
		content = (L"(null)");
	return (ft_putwstr(content, str));
}

char	*ft_castlc(va_list ap, char *str)
{
	wint_t content;

	content = va_arg(ap, wint_t);
	return (printf_putwchar(content, str));
}

char	*ft_casts(va_list ap)
{
	char *content;

	content = va_arg(ap, char*);
	if (content == NULL)
	{
		return ("(null)");
	}
	return (content);
}

char	*ft_castc(va_list ap, char *str)
{
	char content;

	content = va_arg(ap, int);
	return (printf_putchar(content, str));
}
