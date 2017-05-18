/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 19:37:48 by mafabre           #+#    #+#             */
/*   Updated: 2016/06/01 21:21:50 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(void *number, t_flag *flag, t_env *env)
{
	char	*nbr;

	nbr = ft_itoa_base((unsigned long long)number, 16);
	if (flag->minus == 1)
	{
		count_putstr("0x", env);
		count_putstr(nbr, env);
		flag->size -= ft_strlen(nbr) + 1;
		while (flag->size-- > 1)
			(env->n) += count_putchar(' ');
	}
	else
	{
		flag->size -= ft_strlen(nbr) + 1;
		while (flag->size-- > 1)
			(env->n) += count_putchar(' ');
		count_putstr("0x", env);
		count_putstr(nbr, env);
	}
	free(nbr);
}
