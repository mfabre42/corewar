/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 17:07:22 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/30 19:03:36 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../lib_asm/libft.h"

typedef struct		s_env
{
	int		i;
	int		n;
	char	*conv;
}					t_env;

typedef struct		s_flag
{
	int	acc;
	int	diese;
	int	etoile;
	int	size;
	int	h;
	int	j;
	int	l;
	int	minus;
	int	plus;
	int	space;
	int	z;
	int	zero;
}					t_flag;

typedef struct		s_ws
{
	int		w_acc;
	int		w_len;
	int		w_strlen;
	int		w_strlenini;
}					t_ws;

/*
**count_print
*/
int					count_putchar(char c);
void				count_putnbr(long long nbr, t_env *env);
void				count_putstr(char *str, t_env *env);
int					count_putwchar(wchar_t arg, int i);

/*
**parsing
*/
void				parse_flags(const char *format, t_flag *flag, t_env *env);
int					parse_options(const char *format, va_list *ap, t_env *env);

/*
**ft_printf
*/
int					ft_printf(const char *format, ...);
void				print_char(int c, t_flag *flag, t_env *env);
void				print_decimal(long long d, t_flag *f, t_env *env, char c);
void				print_hex(unsigned long long d, t_flag *f, t_env *env);
void				print_hexx(unsigned long long d, t_flag *f, t_env *env);
void				print_modulo(int ch, t_flag *flag, t_env *env);
void				print_octal(unsigned long long d,
						t_flag *f, t_env *env, char c);
void				print_pointer(void *number, t_flag *flag, t_env *env);
void				print_string(char *str, t_flag *f, t_env *env);
void				print_unsigned(unsigned long long d,
						t_flag *f, t_env *env, char c);
void				print_wchar(wchar_t arg, t_flag *f, t_env *env);
void				print_wstring(wchar_t *str, t_flag *f, t_env *env);

/*
**utilities
*/
long long			conv_d(long long d, t_flag *f);
unsigned long long	conv_oux(unsigned long long d, t_flag *f);
char				*ft_itoa_base(unsigned long long n, int base);
char				*str_toupper(char *s);
int					ft_wlen(wchar_t arg);
int					i_len(long long n);

#endif
