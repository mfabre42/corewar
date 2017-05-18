/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 17:53:27 by mafabre           #+#    #+#             */
/*   Updated: 2016/09/30 14:11:47 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					i_len(long long n)
{
	int	lenght;

	if (n == 0)
		return (1);
	lenght = 0;
	if (n < 0)
	{
		lenght++;
		n = -n;
	}
	while (n != 0)
	{
		lenght++;
		n /= 10;
	}
	return (lenght);
}

char				*str_toupper(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

long long			conv_d(long long d, t_flag *f)
{
	if (f->h == 1)
		return ((short)d);
	else if (f->h == 2)
		return ((char)d);
	else if (f->z == 1)
		return ((size_t)d);
	else if (f->j == 1)
		return ((intmax_t)d);
	else if (f->l == 0)
		return ((int)d);
	else
		return (d);
}

unsigned long long	conv_oux(unsigned long long d, t_flag *f)
{
	if (f->h == 1)
		return ((unsigned short)d);
	else if (f->h == 2)
		return ((unsigned char)d);
	else if (f->z == 1)
		return ((size_t)d);
	else if (f->j == 1)
		return ((uintmax_t)d);
	else if (f->l == 0)
		return ((unsigned int)d);
	else
		return (d);
}
