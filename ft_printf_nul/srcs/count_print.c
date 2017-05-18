/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:01:04 by mafabre           #+#    #+#             */
/*   Updated: 2016/06/01 21:42:36 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	count_putstr(char *str, t_env *env)
{
	if (str)
	{
		write(1, str, ft_strlen(str));
		(env->n) += ft_strlen(str);
	}
	else
	{
		write(1, "(null)", 6);
		(env->n) += 6;
	}
}

void	count_putnbr(long long nbr, t_env *env)
{
	long long x;

	if (nbr == -9223372036854775807)
	{
		count_putstr("-9223372036854775807", env);
		return ;
	}
	x = nbr;
	if (nbr < 0)
	{
		env->n += count_putchar('-');
		x = -nbr;
	}
	if (x >= 10)
	{
		count_putnbr(x / 10, env);
		count_putnbr(x % 10, env);
	}
	else
		env->n += count_putchar(x + '0');
}
