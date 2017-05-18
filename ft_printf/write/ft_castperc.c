/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_castperc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 06:24:12 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/06 14:12:24 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_castu(va_list ap)
{
	unsigned int content;

	content = va_arg(ap, unsigned int);
	return (ft_itoa_base(content, 10));
}

char	*ft_castperc(void)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 2);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}
