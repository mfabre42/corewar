/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:35:05 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/02 12:11:51 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define BUF_SIZE 4

# include "../ft_printf/includes/ft_printf.h"
# include "../../libft/libft.h"
# include <fcntl.h>

typedef union	u_convert
{
	unsigned int	c_int;
	unsigned char	c_char[4];
}				t_convert;

typedef struct	s_params
{
	int			d;
	int			n;
	int			np;
	int			p1;
	int			p2;
	int			p3;
	int			p4;
}				t_params;

typedef struct	s_process
{
	unsigned int					*reg;
	int								pc;
	int								start;
	int								carry;
	int								cycle;
	struct s_process				*next;
}				t_process;

typedef struct	s_player
{
	char							*name;
	char							*comm;
	int								process_nbr;
	int								start;
	t_process					*process;
	int								in_life;
	int								last_live;
}				t_player;

typedef struct	s_map
{
	int						check;
	int						cycle;
	int						nb_player;
	int						nb_process;
	unsigned char	*arena;
}								t_map;

typedef struct	s_ocp
{
	char			param1;
	char			param2;
	char			param3;
}				t_ocp;

void			place_in_arena(t_map *map, int dest, int nbr);
unsigned int	hex_to_int(unsigned char a, unsigned char b,
					unsigned char c, unsigned char d);
t_ocp			ocp_master(int	ocp);
void			save_file(char *file, t_params *param, unsigned char *arena);
t_params			save_params(int ac, char **av, unsigned char *arena);
void			send_in_arena(t_convert *tab, t_params *param,
		unsigned char *arena);

#endif
