/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 17:21:02 by mafabre           #+#    #+#             */
/*   Updated: 2016/09/30 14:11:06 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_diese(char *oct, int len, t_flag *f, t_env *env)
{
	if (f->diese == 1 && ft_strcmp(oct, "0"))
	{
		if (f->acc <= len)
		{
			(env->n) += count_putchar('0');
			f->size = f->size - 1;
		}
		else if (f->size - f->acc > 0 && f->minus == 0)
		{
			(env->n) += count_putchar(' ');
			f->size = f->size - 1;
		}
	}
}

static void	print_nominus(char *oct, int len, t_flag *f, t_env *env)
{
	int sign;

	sign = 0;
	if (f->diese > 0 && ft_strcmp(oct, "0") && len >= f->acc)
		f->size = f->size - 1;
	if (f->acc == -5 && f->zero == 1)
	{
		check_diese(oct, len, f, env);
		sign = 1;
	}
	while (f->size > len && f->size-- > f->acc)
		f->acc == -5 && f->zero == 1 ?
		((env->n) += count_putchar('0')) : ((env->n) += count_putchar(' '));
	sign == 0 ? check_diese(oct, len, f, env) : 0;
	f->acc == -1 && ft_strcmp(oct, "0") == 0 && f->diese == 0 ?
	(env->n) += count_putchar(' ') : 0;
	if (f->acc == -1 && ft_strcmp(oct, "0") == 0)
		return ;
	while ((f->acc)-- > len)
		(env->n) += count_putchar('0');
	count_putstr(oct, env);
}

static void	print_minus(char *oct, int len, t_flag *f, t_env *env)
{
	check_diese(oct, len, f, env);
	while ((f->acc)-- > len)
	{
		(env->n) += count_putchar('0');
		(f->size)--;
	}
	f->size = f->size - len;
	if (f->acc == -2 && ft_strcmp(oct, "0") == 0)
	{
		while ((f->size)-- > 0)
			(env->n) += count_putchar(' ');
		return ;
	}
	count_putstr(oct, env);
	while ((f->size)-- > 0)
		(env->n) += count_putchar(' ');
}

void		print_octal(unsigned long long d, t_flag *f, t_env *env, char c)
{
	int		len;
	char	*oct;

	if (c == 'o')
		d = conv_oux(d, f);
	oct = ft_itoa_base(d, 8);
	len = ft_strlen(oct);
	if (f->acc == -1 && f->size == 0 && d == 0)
	{
		if (f->diese == 1)
			(env->n) += count_putchar('0');
		return ;
	}
	else if (f->minus == 1 && f->size > f->acc)
		print_minus(oct, len, f, env);
	else
		print_nominus(oct, len, f, env);
	free(oct);
}
