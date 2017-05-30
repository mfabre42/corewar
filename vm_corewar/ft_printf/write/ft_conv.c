/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:43:14 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 14:42:43 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_casthhu(va_list ap)
{
	char content;

	content = va_arg(ap, int);
	return (ft_itoa_llu(content));
}

char	*ft_casthu(va_list ap)
{
	unsigned short content;

	content = va_arg(ap, int);
	return (ft_itoa_llu(content));
}

char	*ft_castllu(va_list ap)
{
	unsigned long long content;

	content = va_arg(ap, unsigned long long);
	return (ft_itoa_llu(content));
}

char	*ft_castlu(va_list ap)
{
	unsigned long content;

	content = va_arg(ap, unsigned long);
	return (ft_itoa_llu(content));
}

char	*ft_castju(va_list ap)
{
	uintmax_t content;

	content = va_arg(ap, uintmax_t);
	return (ft_itoa_llu(content));
}
