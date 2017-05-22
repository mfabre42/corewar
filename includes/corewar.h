/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:35:05 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/22 16:00:21 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define BUF_SIZE 4

# include "../libft/libft.h"
# include "../srcs/op.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>

typedef union	u_convert
{
	unsigned int	c_int;
	unsigned char	c_char[4];
}				t_convert;

typedef struct	s_params
{
	int			dump;
	int			n;
	int			nb_player;
	int			p1;
	int			p2;
	int			p3;
	int			p4;
}				t_params;

typedef struct	s_player
{
	char				*name;
	char				*comm;
	t_process			*process;
	int					in_life;
	int					last_live;
}				t_player;

typedef struct	s_map
{
	int					mute;
	int					dump;
	int					check;
	int					cycle;
	int					cycle_to_die;
	int					next_ctd;
	unsigned int		nb_live;
	int					nb_player;
	t_player			*player;
	unsigned char		*arena;
}				t_map;

typedef struct	s_ocp
{
	char			param1;
	char			param2;
	char			param3;
}				t_ocp;

typedef struct	s_proto_func
{
	int				num_func;
	void			(*func)(t_map*, t_process*);
}				t_proto_func;

/*
** Fonctions corewar
*/
void			indirect_store(t_map *map, t_process *proc);
void			addition(t_map *map, t_process *proc);
void			aff_char(t_map *map, t_process *proc);
void			func_and(t_map *map, t_process *proc);
void			forkniquer(t_map *map, t_process *proc, int player);
void			indirect_load(t_map *map, t_process *proc);
void			lfork(t_map *map, t_process *proc, int player);
void			live(t_map *map, t_process *proc);
void			ldirect_load(t_map *map, t_process *proc);
void			lindirect_load(t_map *map, t_process *proc);
void			direct_load(t_map *map, t_process *proc);
void			func_or(t_map *map, t_process *proc);
void			direct_store(t_map *map, t_process *proc);
void			indirect_store(t_map *map, t_process *proc);
void			substraction(t_map *map, t_process *proc);
void			func_xor(t_map *map, t_process *proc);
void			jump_if_zero(t_map *map, t_process *proc);
void			fail_func(t_process *proc, int pc, int carry);
void			do_funk(t_process *proc, int cycle, int ft, int what_to_do);

/*
** Fonctions error
*/
void			error_malloc(void);
void			error(int nb);

int				check_last_survivor(t_map *map);
int				is_alive(t_map *map);
void			init_player(t_params *param, t_map *map);
void			cycle_to_die(t_map *map);
void			cp_process(t_map *map, t_process *proc, int player, int adress);
t_player		init_process(t_map *map, int player, int start);
void			kill_player(t_map *map, int n_player);
void			place_in_arena(t_map *map, int dest, int nbr);
unsigned int	hex_to_int(unsigned char a, unsigned char b,
					unsigned char c, unsigned char d);
t_ocp			ocp_master(int	ocp);
void			save_file(char *file, t_params *param, t_map *map);
void			save_params(int ac, char **av, t_map *map, int i);
void			send_in_arena(t_convert *tab, t_params *param, t_map *map);
int				is_register(unsigned int reg);
void			play_game(t_map *map);
unsigned int	read_in_arena(t_map *map, int adress);

#endif
