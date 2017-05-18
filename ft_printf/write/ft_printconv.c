/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:07:06 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 19:03:15 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_printconv3(char *str, va_list ap)
{
	if (CMP(str, "ju", 3) != NULL)
		return (ft_castju(ap));
	else if (CMP(str, "zu", 3) != NULL)
		return (ft_castzu(ap));
	else if (CMP(str, "hhu", 3) != NULL)
		return (ft_casthhu(ap));
	else if (CMP(str, "hu", 3) != NULL)
		return (ft_casthu(ap));
	else if (CMP(str, "llu", 3) != NULL)
		return (ft_castllu(ap));
	else if (CMP(str, "lu", 3) != NULL || CMP(&str[1], "U", 2) != NULL)
		return (ft_castlu(ap));
	else if (str[2] == 'u')
		return (ft_castu(ap));
	else if (CMP(str, "ls", 3) != NULL || CMP(&str[1], "S", 2) != NULL)
		return (ft_castls(ap, &str[1]));
	else if (CMP(str, "lc", 3) != NULL || CMP(&str[1], "C", 2) != NULL)
		return (ft_castlc(ap, &str[1]));
	else if (CMP(&str[1], "s", 2) != NULL)
		return (ft_casts(ap));
	else if (CMP(&str[1], "c", 2) != NULL)
		return (ft_castc(ap, &str[2]));
	return (NULL);
}

char	*ft_printconv2(char *str, va_list ap)
{
	if (CMP(str, "zo", 3) != NULL || CMP(str, "zx", 3) != NULL
		|| CMP(str, "zX", 3) != NULL)
		return (ft_castzo(ap, str[2]));
	else if (CMP(str, "jo", 3) != NULL || CMP(str, "jx", 3) != NULL
		|| CMP(str, "jX", 3) != NULL)
		return (ft_castjo(ap, str[2]));
	else if (CMP(str, "llo", 3) != NULL || CMP(str, "llx", 3) != NULL
		|| CMP(str, "llX", 3) != NULL)
		return (ft_castllo(ap, str[2]));
	else if (CMP(str, "ho", 3) != NULL || CMP(str, "hx", 3) != NULL
		|| CMP(str, "	hX", 3) != NULL)
		return (ft_castho(ap, str[2]));
	else if (CMP(str, "hho", 3) != NULL || CMP(str, "hhx", 3) != NULL
		|| CMP(str, "hhX", 3) != NULL)
		return (ft_casthho(ap, str[2]));
	else if (CMP(str, "lo", 3) != NULL || CMP(str, "lx", 3) != NULL
		|| CMP(str, "lX", 3) != NULL || CMP(&str[1], "O", 2) != NULL)
		return (ft_castlo(ap, str[2]));
	else if (CMP(&str[1], "d", 2) != NULL || CMP(&str[1], "i", 2) != NULL)
		return (ft_castd(ap));
	else if (CMP(&str[1], "o", 2) != NULL || CMP(&str[1], "x", 2) != NULL
		|| CMP(&str[1], "X", 2) != NULL)
		return (ft_casto(ap, str[2]));
	return (ft_printconv3(str, ap));
}

char	*ft_printconv(char *str, va_list ap)
{
	if (CMP(str, "zd", 3) != NULL || CMP(str, "zi", 3) != NULL)
		return (ft_castzd(ap));
	else if (CMP(str, "jd", 3) != NULL || CMP(str, "ji", 3) != NULL)
		return (ft_castjd(ap));
	else if (CMP(str, "lld", 3) != NULL || CMP(str, "lli", 3) != NULL)
		return (ft_castlld(ap));
	else if (CMP(str, "ld", 3) != NULL || CMP(str, "li", 3) != NULL
		|| CMP(&str[1], "D", 2) != NULL)
		return (ft_castld(ap));
	else if (CMP(str, "hhd", 3) != NULL || CMP(str, "hhi", 3) != NULL)
		return (ft_casthhd(ap));
	else if (CMP(str, "hd", 3) != NULL || CMP(str, "hi", 3) != NULL)
		return (ft_casthd(ap));
	else if (CMP(&str[1], "p", 2) != NULL)
		return (ft_castp(ap));
	else if (str[2] == '%')
		return (ft_castperc());
	return (ft_printconv2(str, ap));
}
