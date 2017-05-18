/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 22:54:13 by mafabre           #+#    #+#             */
/*   Updated: 2016/09/30 14:10:55 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_diese(char *hex, t_flag *f, t_env *env)
{
	if (f->diese == 1 && ft_strcmp(hex, "0"))
		count_putstr("0X", env);
}

static void	print_nominus(char *hex, int len, t_flag *f, t_env *env)
{
	int sign;

	sign = 0;
	if (f->diese > 0 && ft_strcmp(hex, "0"))
		f->size = f->size - 2;
	if (f->acc == -5 && f->zero == 1)
	{
		check_diese(hex, f, env);
		sign = 1;
	}
	while (f->size > len && f->size-- > f->acc)
		f->acc == -5 && f->zero == 1 ?
		((env->n) += count_putchar('0')) : ((env->n) += count_putchar(' '));
	sign == 0 ? check_diese(hex, f, env) : 0;
	f->acc == -1 && ft_strcmp(hex, "0") == 0 && f->diese == 0 ?
	(env->n) += count_putchar(' ') : 0;
	if (f->acc == -1 && ft_strcmp(hex, "0") == 0)
		return ;
	while ((f->acc)-- > len)
		(env->n) += count_putchar('0');
	count_putstr(hex, env);
}

static void	print_minus(char *hex, int len, t_flag *f, t_env *env)
{
	if (f->diese > 0 && ft_strcmp(hex, "0"))
		f->size = f->size - 2;
	check_diese(hex, f, env);
	while ((f->acc)-- > len)
	{
		(env->n) += count_putchar('0');
		(f->size)--;
	}
	f->size = f->size - len;
	if (f->acc == -2 && ft_strcmp(hex, "0") == 0)
	{
		while ((f->size)-- > 0)
			(env->n) += count_putchar(' ');
		return ;
	}
	count_putstr(hex, env);
	while ((f->size)-- > 0)
		(env->n) += count_putchar(' ');
}

void		print_hexx(unsigned long long d, t_flag *f, t_env *env)
{
	int		len;
	char	*hex;

	d = conv_oux(d, f);
	hex = str_toupper(ft_itoa_base(d, 16));
	len = ft_strlen(hex);
	if (f->acc == -1 && f->size == 0 && d == 0)
		return ;
	else if (f->minus == 1 && f->size > f->acc)
		print_minus(hex, len, f, env);
	else
		print_nominus(hex, len, f, env);
	free(hex);
}
