/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 22:11:48 by mafabre           #+#    #+#             */
/*   Updated: 2017/06/01 16:58:27 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** initialize all struct
*/

void		init_file_firstparse(t_file *file)
{
	file->label = NULL;
	file->line = 0;
	file->start = 0;
	file->file_size = 0;
	file->int_i = 0;
	file->i = 0;
	file->j = 0;
	file->pc = 0;
	file->has_name = 0;
	file->has_comm = 0;
}

void		init_file_secondparse(t_file *file)
{
	file->i = 0;
	file->j = 0;
	file->line = file->start;
	file->pc = 0;
	if (!(file->int_file = (int *)malloc(sizeof(int) * (file->file_size + 1))))
		exit_error_nl("Erreur de malloc.");
	if (!(file->size_hex =
		(int *)ft_memalloc(sizeof(int) * (file->file_size + 1))))
		exit_error_nl("Erreur de malloc.");
}

void		init_line(t_line *line)
{
	line->i = 0;
	line->inst = -1;
	line->nb_params = 0;
	line->op_code = 0;
	line->size_line = 0;
	line->param_val[0] = 0;
	line->param_val[1] = 0;
	line->param_val[2] = 0;
	line->params[0] = 0;
	line->params[1] = 0;
	line->params[2] = 0;
	line->has_label = 0;
	line->separator = 0;
}
