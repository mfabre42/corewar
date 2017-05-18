/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:45:45 by mafabre           #+#    #+#             */
/*   Updated: 2016/09/30 14:10:34 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_sign(long long d, t_flag *f, t_env *env)
{
	if (f->space > 0 && f->plus == 0)
		if (d < 0)
			(env->n) += count_putchar('-');
		else
			(env->n) += count_putchar(' ');
	else
	{
		if (f->minus == 1 && f->size > f->acc)
		{
			if (d >= 0 && f->plus == 1)
				(env->n) += count_putchar('+');
			if (d < 0)
			{
				(env->n) += count_putchar('-');
				(f->size)--;
			}
			f->acc == -1 && d == 0 ? (env->n) += count_putchar(' ') : 0;
		}
		else
		{
			d >= 0 && f->plus == 1 ? (env->n) += count_putchar('+') : 0;
			d < 0 ? (env->n) += count_putchar('-') : 0;
		}
	}
}

static void	print_nominus(long long d, int len, t_flag *f, t_env *env)
{
	int sign;

	sign = 0;
	if ((d >= 0 && (f->plus > 0 || f->space > 0)) || (len <= f->acc && d < 0))
		(f->size)--;
	if (f->acc == -5 && f->zero == 1)
	{
		check_sign(d, f, env);
		sign = 1;
	}
	while (f->size > len && f->size-- > f->acc)
		f->acc == -5 && f->zero == 1 ?
		((env->n) += count_putchar('0')) : ((env->n) += count_putchar(' '));
	sign == 0 ? check_sign(d, f, env) : 0;
	f->acc == -1 && d == 0 && f->plus == 0 ? (env->n) += count_putchar(' ') : 0;
	if (f->acc == -1 && d == 0)
		return ;
	if (d < 0)
	{
		d = -d;
		len--;
	}
	while ((f->acc)-- > len)
		(env->n) += count_putchar('0');
	count_putnbr(d, env);
}

static void	print_minus(long long d, int len, t_flag *f, t_env *env)
{
	if ((f->plus > 0 && d >= 0) || f->space > 0)
		(f->size)--;
	check_sign(d, f, env);
	if (d < 0)
	{
		d = -d;
		len--;
	}
	while ((f->acc)-- > len)
	{
		(env->n) += count_putchar('0');
		(f->size)--;
	}
	f->size = f->size - len;
	if (f->acc == -2 && d == 0)
	{
		while ((f->size)-- > 0)
			(env->n) += count_putchar(' ');
		return ;
	}
	count_putnbr(d, env);
	while ((f->size)-- > 0)
		(env->n) += count_putchar(' ');
}

void		print_decimal(long long d, t_flag *f, t_env *env, char c)
{
	int		len;
	char	*minlong;

	minlong = ft_itoa_base(d, 10);
	if (ft_strcmp("9223372036854775808", minlong) == 0)
	{
		count_putstr("-9223372036854775808", env);
		return ;
	}
	if (c == 'd')
		d = conv_d(d, f);
	len = i_len(d);
	if (f->acc == -1 && f->size == 0 && d == 0)
	{
		if (f->plus == 1)
			(env->n) += count_putchar('+');
		if (f->space == 1)
			(env->n) += count_putchar(' ');
		return ;
	}
	else if (f->minus == 1 && f->size > f->acc)
		print_minus(d, len, f, env);
	else
		print_nominus(d, len, f, env);
	free(minlong);
}
