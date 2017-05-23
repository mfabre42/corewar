/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:12:54 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/23 11:08:50 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Base of the program.
** Save file in int, then conv in hex.
*/

void		get_label_value(t_file *file, t_line *line)
{
	t_label	*tmp;
	int		label_value;

	tmp = file->label;
	label_value = 0;
	while (tmp != NULL)
	{
		if (ft_strcmp(&file->tmp_line[line->i][line->j], tmp->l_name) == 0)
		{
			label_value = tmp->l_value - file->pc;
			file->tmp_line[line->i] = ft_strdup("");
			file->tmp_line[line->i] =
			ft_strdup(ft_itoa(label_value));
			file->tmp_line[line->i] = ft_strjoin("%", file->tmp_line[line->i]);
			line->j = 1;
			return ;
		}
		tmp = tmp->next;
	}
	exit_error("label incorrect.", file);
}

void		int_line(t_file *file, t_line *line)
{
	if (file->tmp_line[line->i])
	{
		if (file->tmp_line[0][ft_strlen(file->tmp_line[0]) - 1] == ':')
		{
			line->has_label += 1;
			line->i++;
		}
		if (file->tmp_line[line->i])
			save_inst(file, line);
	}
	while (file->tmp_line[line->i])
	{
		if (file->tmp_line[line->i][0] == '#')
			break ;
		if (file->tmp_line[line->i][0] == 'r')
			save_register(file, line);
		else if (file->tmp_line[line->i][0] == DIRECT_CHAR)
			save_direct(file, line);
		else if (file->tmp_line[line->i][0] != DIRECT_CHAR)
			save_index(file, line, 0);
		line->i++;
	}
	if (line->inst != -1)
		save_opc(file, line);
	file->pc += line->size_line;
}

void		conv_file(t_file *file)
{
	t_line line;

	while (file->file_s[file->line])
	{
		init_line(&line);
		move_to_next_line(file);
		if (file->file_s[file->line] == NULL)
			break ;
		file->tmp_line = ft_strsplit(file->file_s[file->line], ' ');
		int_line(file, &line);
		file->line++;
	}
	conv_in_hex(file, &line);
}
