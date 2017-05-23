/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:38:02 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/23 13:20:04 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Save inst and params as int value in file->int_file.
** Save size of the conv in hex. 1, 2 or 4 bytes in file->size_hex.
*/

void		save_inst(t_file *file, t_line *line)
{
	int i;

	i = 0;
	while (i < 16 && ft_strcmp(g_op_tab[i].name,
		file->tmp_line[0 + line->has_label]) != 0)
	{
		i++;
	}
	if (i == 16)
		exit_error("mauvaise instruction.", file);
	line->inst = i + 1;
	line->size_line = line->size_line + 1 + g_op_tab[i].has_opc;
	file->int_file[file->int_i] = line->inst;
	file->size_hex[file->int_i] = 1;
	file->int_i++;
	if (g_op_tab[i].has_opc == 1)
	{
		line->tmp_opc = file->int_i;
		file->size_hex[file->int_i] = 1;
		file->int_i++;
	}
	line->i++;
}

void		save_register(t_file *file, t_line *line)
{
	line->j = 1;
	if (file->tmp_line[line->i][ft_strlen(file->tmp_line[line->i]) - 1] == ',')
		check_separator(file, line);
	while (file->tmp_line[line->i][line->j])
	{
		if (file->tmp_line[line->i][line->j] >= '0' &&
			file->tmp_line[line->i][line->j] <= '9')
			line->j++;
		else
			exit_error("numero de registre invalide.", file);
	}
	file->int_file[file->int_i] = ft_atoi(&file->tmp_line[line->i][1]);
	file->size_hex[file->int_i] = 1;
	line->params[line->nb_params] = T_REG;
	line->nb_params += 1;
	line->size_line = line->size_line + 1;
	file->int_i++;
}

void		save_direct2(t_file *file, t_line *line)
{
	file->int_file[file->int_i] = ft_atoi(&file->tmp_line[line->i][1]);
	file->size_hex[file->int_i] = g_op_tab[line->inst - 1].dir_size;
	line->params[line->nb_params] = T_DIR;
	line->nb_params += 1;
	line->size_line += g_op_tab[line->inst - 1].dir_size;
	file->int_i++;
}

void		save_direct(t_file *file, t_line *line)
{
	line->j = 1;
	if (file->tmp_line[line->i][ft_strlen(file->tmp_line[line->i]) - 1] == ',')
		check_separator(file, line);
	if (file->tmp_line[line->i][line->j] == LABEL_CHAR)
	{
		line->j++;
		get_label_value(file, line);
	}
	if (file->tmp_line[line->i][line->j] == '-')
		line->j++;
	while (file->tmp_line[line->i][line->j])
	{
		if (file->tmp_line[line->i][line->j] >= '0' &&
			file->tmp_line[line->i][line->j] <= '9')
			line->j++;
		else
			exit_error("parametre incorrect.", file);
	}
	save_direct2(file, line);
}

void		save_index(t_file *file, t_line *line, int label)
{
	line->j = 0;
	if (file->tmp_line[line->i][ft_strlen(file->tmp_line[line->i]) - 1] == ',')
		check_separator(file, line);
	if (file->tmp_line[line->i][line->j] == LABEL_CHAR)
	{
		line->j++;
		get_label_value(file, line);
		label = 1;
	}
	if (file->tmp_line[line->i][line->j] == '-')
		line->j++;
	while (file->tmp_line[line->i][line->j])
	{
		if (file->tmp_line[line->i][line->j] >= '0' &&
			file->tmp_line[line->i][line->j] <= '9')
			line->j++;
		else
			exit_error("parametre incorrect.", file);
	}
	file->int_file[file->int_i] = ft_atoi(&file->tmp_line[line->i][0 + label]);
	file->size_hex[file->int_i] = 2;
	line->params[line->nb_params] = T_IND;
	line->nb_params += 1;
	line->size_line += 2;
	file->int_i++;
}
