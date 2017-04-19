/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:35:05 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/18 19:42:18 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define BUF_SIZE 4

typedef union u_convert
{
  int   c_int;
  char  c_char[4];
}             t_convert;

# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <sys/stat.h>

#endif
