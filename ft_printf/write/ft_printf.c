/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:49:52 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/08 18:00:19 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			i;
	char		*str;
	int			retu;
	va_list		ap;
	char		*tmp;

	str = ft_strdup((char*)format);
	tmp = str;
	va_start(ap, format);
	i = 0;
	retu = 0;
	while (str[i])
		if (str[i] == '%')
		{
			retu = writestr(str, &str[i], retu);
			str = wheel_of_destiny(&str[i + 1], ap, &retu);
			i = 0;
		}
		else
			i++;
	retu = writestr(str, &str[i], retu);
	va_end(ap);
	free(tmp);
	return (retu);
}
