/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:24:53 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 20:31:41 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <inttypes.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <wchar.h>
# include <stdint.h>
# define CMP ft_strnstr

int		ft_charwlen(wchar_t carac);
char	*ft_free(char *ret, char *str);
char	*ft_castu(va_list ap);
char	*ft_castperc();
int		ft_findconv(char *str);
char	*ft_casthhu(va_list ap);
char	*ft_casthu(va_list ap);
char	*ft_castllu(va_list ap);
char	*ft_castlu(va_list ap);
char	*ft_castju(va_list ap);
char	*ft_castzu(va_list ap);
char	*ft_castls(va_list ap, char *str);
char	*ft_castlc(va_list ap, char *str);
char	*ft_casts(va_list ap);
char	*ft_castc(va_list ap, char *str);
char	*ft_castho(va_list ap, char c);
char	*ft_casthho(va_list ap, char c);
char	*ft_castlo(va_list ap, char c);
char	*ft_castllo(va_list ap, char c);
char	*ft_castjo(va_list ap, char c);
char	*ft_castzo(va_list ap, char c);
char	*ft_casto(va_list ap, char c);
char	*ft_castp(va_list ap);
char	*ft_castlld(va_list ap);
char	*ft_castld(va_list ap);
char	*ft_casthhd(va_list ap);
char	*ft_casthd(va_list ap);
char	*ft_castzd(va_list ap);
char	*ft_castjd(va_list ap);
char	*ft_castd(va_list ap);
char	*ft_printconv(char *str, va_list ap);
char	*optn_minus(char *str, int nbr);
char	*optn_zero(char *str, int nbr);
char	*optn_space(char *str, int nbr);
char	*optn_point(char *str, int nbr);
char	*optn_plus(char *str, int nbr);
char	*optn_oct(char *ret, char *str);
char	*optn_nbr(char *str, int nbr);
char	*printf_option(char *str, char *ret);
char	*ft_itoa_intmax(intmax_t nbr, int base);
char	*ft_itoa_llu(uintmax_t nbr);
int		ft_isspec(char *str);
int		ft_putstr_printf(char *s, int retu, char *str);
char	*printf_putwchar(wchar_t caract, char *str);
char	*ft_putwstr(wchar_t *s, char *str);
int		ft_putwchar(wchar_t carac, int retu);
char	*printf_putnbr(long long nbr);
char	*printf_putoct(long long nbr);
char	*printf_puthex(unsigned long long nbr);
char	*printf_puthexa(long long nbr);
char	*printf_putstr(long long nbr);
char	*printf_putchar(long long nbr, char *str);
char	*printf_putpoint(long long nbr);
int		ft_printf(const char *format, ...);
int		writestr(char *begin, char *end, int retu);
char	*wheel_of_destiny(char *nn, va_list content, int *retu);

#endif
