/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:09:10 by mafabre           #+#    #+#             */
/*   Updated: 2016/09/30 14:11:18 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_nominus(char *un_int, int len, t_flag *f, t_env *env)
{
	while (f->size > len && f->size-- > f->acc)
		f->acc == -5 && f->zero == 1 ?
		((env->n) += count_putchar('0')) : ((env->n) += count_putchar(' '));
	f->acc == -1 && ft_strcmp(un_int, "0") == 0 ?
	(env->n) += count_putchar(' ') : 0;
	if (f->acc == -1 && ft_strcmp(un_int, "0") == 0)
		return ;
	while ((f->acc)-- > len)
		(env->n) += count_putchar('0');
	count_putstr(un_int, env);
}

static void	print_minus(char *un_int, int len, t_flag *f, t_env *env)
{
	while ((f->acc)-- > len)
	{
		(env->n) += count_putchar('0');
		(f->size)--;
	}
	f->size = f->size - len;
	if (f->acc == -2 && ft_strcmp(un_int, "0") == 0)
	{
		while ((f->size)-- > 0)
			(env->n) += count_putchar(' ');
		return ;
	}
	count_putstr(un_int, env);
	while ((f->size)-- > 0)
		(env->n) += count_putchar(' ');
}

void		print_unsigned(unsigned long long d, t_flag *f, t_env *env, char c)
{
	int		len;
	char	*un_int;

	if (c == 'u')
		d = conv_oux(d, f);
	un_int = ft_itoa_base(d, 10);
	len = ft_strlen(un_int);
	if (f->acc == -1 && f->size == 0 && d == 0)
		return ;
	else if (f->minus == 1 && f->size > f->acc)
		print_minus(un_int, len, f, env);
	else
		print_nominus(un_int, len, f, env);
	free(un_int);
}
