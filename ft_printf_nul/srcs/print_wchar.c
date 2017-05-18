/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 20:30:46 by mafabre           #+#    #+#             */
/*   Updated: 2016/09/30 14:11:27 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_wlen(wchar_t arg)
{
	int	i;

	i = 0;
	if (arg <= 0x7F)
		i++;
	else if (arg <= 0x7FF)
		i += 2;
	else if (arg <= 0xFFFF)
		i += 3;
	else if (arg <= 0x1FFFF)
		i += 4;
	return (i);
}

static int	count_wputchar(wchar_t c)
{
	write(1, &c, 1);
	return (1);
}

int			count_putwchar(wchar_t arg, int i)
{
	if (arg <= 0x7F)
		i = count_wputchar(arg);
	else if (arg <= 0x7FF)
	{
		count_wputchar((arg >> 6) + 0xC0);
		count_wputchar((arg & 0x3F) + 0x80);
		i = 2;
	}
	else if (arg <= 0xFFFF)
	{
		count_wputchar((arg >> 12) + 0xE0);
		count_wputchar(((arg >> 6) & 0x3F) + 0x80);
		count_wputchar((arg & 0x3F) + 0x80);
		i = 3;
	}
	else if (arg <= 0x1FFFF)
	{
		count_wputchar((arg >> 18) + 0xF0);
		count_wputchar(((arg >> 12) & 0x3F) + 0x80);
		count_wputchar(((arg >> 6) & 0x3F) + 0x80);
		count_wputchar((arg & 0x3F) + 0x80);
		i = 4;
	}
	return (i);
}

void		print_wchar(wchar_t arg, t_flag *f, t_env *env)
{
	f->size -= ft_wlen(arg);
	if (f->minus == 0)
	{
		while (f->size-- > 0)
			env->n += count_putchar(' ');
		env->n += count_putwchar(arg, 0);
	}
	else
	{
		env->n += count_putwchar(arg, 0);
		while (f->size-- > 0)
			env->n += count_putchar(' ');
	}
}
