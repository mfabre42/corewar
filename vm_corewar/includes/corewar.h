/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:35:05 by mafabre           #+#    #+#             */
/*   Updated: 2017/06/01 20:11:41 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define BUF_SIZE 4
# define ARENA map->arena
# define ARENA_CLAIM map->arena_claim
# define POS bin->pos
# define PC bin->pc
# define OCP bin->ocp
# define REG_NBR bin->reg_nbr
# define PPOS bin.pos
# define PPC bin.pc
# define POCP bin.ocp
# define PREG_NBR bin.reg_nbr

# include "../lib_vm/libft.h"
# include "../srcs/op.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <curses.h>

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
	int			i;
}				t_params;

typedef struct	s_player
{
	char				*name;
	char				*comm;
	t_process			*process;
	int					number;
	int					in_life;
	int					last_live;
}				t_player;

typedef struct	s_map
{
	int					mute;
	int					mute_aff;
	int					visu;
	int					dump;
	int					ndump;
	int					check;
	int					cycle;
	int					cycle_to_die;
	int					next_ctd;
	unsigned int		nb_live;
	int					nb_player;
	t_player			*player;
	unsigned char		*arena;
	unsigned int		*arena_claim;
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

typedef struct	s_bin
{
	int		pos;
	t_ocp	ocp;
	int		pc;
	int		reg_nbr;
}				t_bin;

typedef struct	s_visu
{
	char			**namejoueur;
	int				row;
	int				col;
}				t_visu;

/*
** Fonctions corewar
*/
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
void			direct_store(t_map *map, t_process *proc, int player);
void			indirect_store(t_map *map, t_process *proc, int player);
void			substraction(t_map *map, t_process *proc);
void			func_xor(t_map *map, t_process *proc);
void			jump_if_zero(t_map *map, t_process *proc);
void			do_funk(t_process *proc, int cycle, int ft, int what_to_do);

/*
** Fonctions error
*/
void			error_malloc(void);
void			error(int nb);
void			print_usage(void);
int				is_reg(unsigned int reg, t_process *proc, int pc);

/*
** Recuperation fichier
*/
void			check_n_np(int ac, char **av, t_params *param);
void			save_file(char *file, t_params *param, t_map *map, int tmp);
void			save_params(int ac, char **av, t_map *map);
void			send_in_arena(t_convert *tab, t_params *param, t_map *map);

t_bin			init_bin(t_map *map, t_process *proc);
void			init_player(t_params *param, t_map *map);
t_player		init_process(t_map *map, int player, int start);
int				check_last_survivor(t_map *map);
int				is_alive(t_map *map);
t_ocp			ocp_master(int	ocp);
unsigned int	hex_to_int(unsigned char a, unsigned char b,
					unsigned char c, unsigned char d);
void			cycle_to_die(t_map *map);
void			kill_player(t_map *map, int n_player);
void			kill_process(t_map *map, int n_player, t_process *proc);
void			cp_process(t_map *map, t_process *proc, int player, int adress);
void			place_in_arena(t_map *map, int dest, int nbr, int player);
unsigned int	read_in_arena(t_map *map, int adress);
void			print_map(t_map *map);
void			play_game(t_map *map);

/*
** Visualisateur
*/
void			print_arena_visu(t_map *map, t_visu *visu);
void			print_visu(t_map *map, t_visu *visu);
void			display_winner(t_map *map);
t_visu			init_visu(t_map *map);
void			check_resize(t_visu *visu);
void			info_map(t_map *map);
void			info_joueur(t_map *map);

#endif
