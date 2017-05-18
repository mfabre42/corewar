/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 17:45:59 by mafabre           #+#    #+#             */
/*   Updated: 2016/09/30 14:11:42 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_wstr_len(wchar_t *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x1FFFF)
			i += 4;
		str++;
	}
	return (i);
}

static void	print_wsminus2(wchar_t *str, t_ws *ws, t_flag *f, t_env *env)
{
	if (f->acc != 0 && f->acc < ws->w_strlen)
	{
		while (*str && ((f->acc -= ft_wlen(*str)) >= 0))
			(env->n) += count_putwchar(*str++, 0);
		while (((f->size)--) - ws->w_acc > 0 - ws->w_len)
			(env->n) += count_putchar(' ');
	}
	else
	{
		while (*str && (ws->w_strlen -= ft_wlen(*str)) >= 0 && f->acc == 0)
			(env->n) += count_putwchar(*str++, 0);
		while (*str && (ws->w_strlen -= ft_wlen(*str)) >= -1
			&& (((f->acc -= ft_wlen(*str)) - ws->w_strlen) >= 0))
			(env->n) += count_putwchar(*str++, 0);
		while (((f->size)-- - ws->w_strlenini) > 0)
			(env->n) += count_putchar(' ');
	}
}

static void	print_wsminus(wchar_t *str, t_ws *ws, t_flag *f, t_env *env)
{
	int		count;
	int		wlen;

	ws->w_acc = f->acc;
	ws->w_len = f->acc;
	ws->w_strlenini = ws->w_strlen;
	count = 0;
	while (*str && ws->w_len >= 0)
	{
		wlen = ft_wlen(*str++);
		count++;
		if (ws->w_len >= wlen)
			ws->w_len = ws->w_len - wlen;
		else
			break ;
	}
	while (count-- > 0)
		ft_wlen(*str--);
	print_wsminus2(str, ws, f, env);
}

static void	print_wstring2(wchar_t *str, t_flag *f, t_env *env, t_ws *ws)
{
	if (f->acc < 0)
		while ((f->size)-- > 0)
			(env->n) += count_putchar(' ');
	else if (f->minus == 1)
		print_wsminus(str, ws, f, env);
	else if (f->acc > 0 && f->acc < ws->w_strlen)
	{
		while (((f->size)-- - f->acc) > 0 - ws->w_len)
			(env->n) += count_putchar(' ');
		while (*str && ((f->acc -= ft_wlen(*str)) >= 0))
			(env->n) += count_putwchar(*str++, 0);
	}
	else
	{
		while (((f->size)-- - ws->w_strlen) > 0)
			(env->n) += count_putchar(' ');
		while (*str && ws->w_strlen >= 0 && f->acc == 0)
		{
			(env->n) += count_putwchar(*str++, 0);
			ws->w_strlen -= ft_wlen(*str);
		}
		while (*str && (ws->w_strlen -= ft_wlen(*str)) >= -1
			&& ((f->acc -= ft_wlen(*str))) >= 0)
			(env->n) += count_putwchar(*str++, 0);
	}
}

void		print_wstring(wchar_t *str, t_flag *f, t_env *env)
{
	t_ws	ws;
	int		wlen;
	int		count;

	count = 0;
	if (str == NULL)
	{
		count_putstr(NULL, env);
		return ;
	}
	f->acc = (f->acc == -5) ? 0 : f->acc;
	ws.w_len = f->acc;
	ws.w_strlen = ft_wstr_len(str);
	while (*str && ws.w_len >= 0)
	{
		wlen = ft_wlen(*str++);
		count++;
		if (ws.w_len >= wlen)
			ws.w_len = ws.w_len - wlen;
		else
			break ;
	}
	while (count-- > 0)
		ft_wlen(*str--);
	print_wstring2(str, f, env, &ws);
}
