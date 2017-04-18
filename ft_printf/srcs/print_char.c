/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:26:51 by mafabre           #+#    #+#             */
/*   Updated: 2016/06/01 20:36:14 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_char(int ch, t_flag *flag, t_env *env)
{
	if (flag->minus == 1)
	{
		(env->n) += count_putchar(ch);
		while (flag->size-- > 1)
			(env->n) += count_putchar(' ');
	}
	else
	{
		while (flag->size-- > 1)
			(env->n) += count_putchar(' ');
		(env->n) += count_putchar(ch);
	}
}
