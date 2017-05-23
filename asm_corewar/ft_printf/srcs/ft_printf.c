/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 19:46:27 by mafabre           #+#    #+#             */
/*   Updated: 2016/06/01 20:31:40 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_env	env;
	va_list	ap;

	env.i = 0;
	env.n = 0;
	env.conv = ft_strdup("sSpdDioOuUxXcC%");
	va_start(ap, format);
	while (format[env.i])
	{
		if (format[env.i] == '%')
		{
			(env.i)++;
			parse_options(format, &ap, &env);
		}
		else
			env.n += count_putchar(format[env.i]);
		(env.i)++;
	}
	va_end(ap);
	free(env.conv);
	return (env.n);
}
