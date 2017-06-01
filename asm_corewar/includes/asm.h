/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:48:47 by mafabre           #+#    #+#             */
/*   Updated: 2017/06/01 17:19:07 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define BUF_SIZE 1

# include "op.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../lib_asm/libft.h"
# include <fcntl.h>

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

typedef union		u_convert
{
	int				c_int;
	unsigned char	c_char[4];
}					t_convert;

typedef struct		s_line
{
	int				inst;
	int				i;
	int				j;
	int				has_label;
	int				tmp_opc;
	int				separator;
	int				param_val[4];
	int				nb_params;
	int				params[4];
	int				op_code;
	int				size_line;
}					t_line;

typedef struct		s_file
{
	t_header		header;
	t_label			*label;
	int				line;
	char			**tmp_line;
	int				*int_file;
	int				*size_hex;
	char			**file_s;
	char			*tmp_filename;
	int				file_size;
	int				int_i;
	int				i;
	int				j;
	int				start;
	int				pc;
	char			*filename;
	char			*name;
	char			*comm;
	int				has_name;
	int				has_comm;
}					t_file;

t_op				g_op_tab[17];
/*
** exit
*/
void				exit_error(char *error, t_file *file);
void				exit_error_nl(char *error);
/*
** init_struct
*/
void				init_file_firstparse(t_file *file);
void				init_file_secondparse(t_file *file);
void				init_line(t_line *line);
/*
** first parse, save size and label
*/
void				check_label_inst(t_file *file);
void				save_name_comment(t_file *file);
void				save_label(t_file *file, t_line *line);
void				save_size_and_label(t_file *file);
void				move_to_next_line(t_file *file);
/*
** second parse, save inst and params and convert all data in int
*/
void				conv_file(t_file *file);
void				save_inst(t_file *file, t_line *line);
void				save_register(t_file *file, t_line *line);
void				save_direct(t_file *file, t_line *line);
void				save_index(t_file *file, t_line *line, int label);
void				get_label_value(t_file *file, t_line *line);
void				save_opc(t_file *file, t_line *line);
void				check_separator(t_file *file, t_line *line);
/*
** last phase, save and write in hex
*/
void				conv_in_hex(t_file *file);

#endif
