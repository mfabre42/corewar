/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:35:05 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/27 15:12:26 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define BUF_SIZE 4

# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>

typedef union	u_convert
{
  unsigned int	c_int;
  unsigned char	c_char[4];
}				t_convert;

typedef struct	s_params
{
	int		d;
	int		n;
	int		np;
	int		p1;
	int		p2;
	int		p3;
	int		p4;
}				t_params;

void		save_file(char *file, t_params *param, unsigned char *arena);
void		save_params(int ac, char **av, unsigned char *arena);
void		send_in_arena(t_convert *tab, t_params *param, unsigned char *arena);

#endif
