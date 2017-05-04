/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:35:05 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/04 18:45:40 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define BUF_SIZE 4

# include "../srcs/op.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../libft/libft.h"
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

typedef struct	s_player
{
	char				*name;
	char				*comm;
	int					process_nbr;
	int					start;
	t_process			*process;
	int					in_life;
	int					last_live;
}				t_player;

typedef struct	s_map
{
	int					check;
	int					cycle;
	int					nb_player;
	int					nb_process;
	t_player			*player;
	unsigned char		*arena;
}				t_map;

typedef struct	s_ocp
{
	char			param1;
	char			param2;
	char			param3;
}				t_ocp;

/*
** Fonctions corewar
*/
void			indirect_store(t_map *map, t_process *proc);

t_player		init_process(t_map *map, int player, int start);
void			place_in_arena(t_map *map, int dest, int nbr);
unsigned int	hex_to_int(unsigned char a, unsigned char b,
					unsigned char c, unsigned char d);
t_ocp			ocp_master(int	ocp);
void			save_file(char *file, t_params *param, t_map *map);
t_params		save_params(int ac, char **av, t_params param, t_map *map);
void			send_in_arena(t_convert *tab, t_params *param, t_map *map);
int				is_register(unsigned int reg);
void			play_game(t_map *map);

#endif
