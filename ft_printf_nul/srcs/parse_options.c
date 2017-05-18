/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 16:39:40 by mafabre           #+#    #+#             */
/*   Updated: 2016/09/30 14:10:19 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_flags(t_flag *flag)
{
	flag->acc = -5;
	flag->diese = 0;
	flag->etoile = 0;
	flag->size = 0;
	flag->h = 0;
	flag->j = 0;
	flag->l = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->z = 0;
	flag->zero = 0;
}

static void	parse_conv2(const char *format, va_list *ap, t_flag *f, t_env *env)
{
	if (format[env->i] == 'U')
		print_unsigned(va_arg(*ap, unsigned long long), f, env, 'U');
	else if (format[env->i] == 'p')
		print_pointer(va_arg(*ap, void*), f, env);
	else if (format[env->i] == '%')
		print_modulo('%', f, env);
}

static void	parse_conv(const char *format, va_list *ap, t_flag *f, t_env *env)
{
	if (format[env->i] == 'c' && f->l == 0)
		print_char(va_arg(*ap, int), f, env);
	else if (format[env->i] == 'C' || (format[env->i] == 'c' && f->l == 1))
		print_wchar(va_arg(*ap, wchar_t), f, env);
	else if (format[env->i] == 's' && f->l == 0)
		print_string(va_arg(*ap, char *), f, env);
	else if (format[env->i] == 'S' || (format[env->i] == 's' && f->l == 1))
		print_wstring(va_arg(*ap, wchar_t *), f, env);
	else if (format[env->i] == 'd' || format[env->i] == 'i')
		print_decimal(va_arg(*ap, long long), f, env, 'd');
	else if (format[env->i] == 'D')
		print_decimal(va_arg(*ap, long long), f, env, 'D');
	else if (format[env->i] == 'x')
		print_hex(va_arg(*ap, unsigned long long), f, env);
	else if (format[env->i] == 'X')
		print_hexx(va_arg(*ap, unsigned long long), f, env);
	else if (format[env->i] == 'o')
		print_octal(va_arg(*ap, unsigned long long), f, env, 'o');
	else if (format[env->i] == 'O')
		print_octal(va_arg(*ap, unsigned long long), f, env, 'O');
	else if (format[env->i] == 'u')
		print_unsigned(va_arg(*ap, unsigned long long), f, env, 'u');
	else
		parse_conv2(format, ap, f, env);
}

int			parse_options(const char *format, va_list *ap, t_env *env)
{
	t_flag flag;

	init_flags(&flag);
	parse_flags(format, &flag, env);
	if (flag.etoile == 1)
		return (0);
	parse_conv(format, ap, &flag, env);
	return (0);
}
