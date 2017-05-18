/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_of_destiny.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:26:18 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 18:30:53 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_isconv(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

int		ft_findconv(char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '#'
		|| str[i] == '.' || str[i] == 'h' || str[i] == 'l' || str[i] == 'j'
		|| str[i] == 'z' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (ft_isconv(str[i]) == 1)
		return (i);
	return (-1);
}

int		ft_passarg(char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '#'
		|| str[i] == '.' || str[i] == 'h' || str[i] == 'l' || str[i] == 'j'
		|| str[i] == 'z' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	return (i);
}

char	*wheel(char *str, va_list ap, int *retu, int i)
{
	int		x;
	char	*ret;

	x = 0;
	if ((i = ft_findconv(str)) != -1)
	{
		ret = ft_printconv(&str[i - 2], ap);
		if (str[i] == 83 || str[i] == 67 || (str[i] == 's' && str[i - 1] == 'l')
			|| (str[i] == 'c' && str[i - 1] == 'l') || str[i] == 'c')
		{
			*retu = *retu + ft_atoi(ret);
			free(ret);
		}
		else
		{
			ret = printf_option(str, ret);
			*retu = ft_putstr_printf(ret, *retu, str);
		}
	}
	else
	{
		i = ft_passarg(str);
		return (&str[i]);
	}
	return (&str[i + 1]);
}

char	*wheel_of_destiny(char *str, va_list ap, int *retu)
{
	return (wheel(str, ap, retu, 0));
}
