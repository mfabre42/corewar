/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_and_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:07:11 by mafabre           #+#    #+#             */
/*   Updated: 2017/06/01 17:19:43 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Save size of the file.
** Save labels and their initial value in file->label.
*/

void		check_inst(t_file *file, t_line *line)
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
	file->file_size = file->file_size + 1 + g_op_tab[i].has_opc;
	line->i++;
}

void		check_label_char(t_file *file)
{
	t_label	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = file->label;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->l_name[i])
		{
			if (ft_strchr(LABEL_CHARS, tmp->l_name[i]) == NULL)
				exit_error("mauvais caractere pour le label.", file);
			i++;
		}
		tmp = tmp->next;
	}
}

void		save_label(t_file *file, t_line *line)
{
	int		doublon;
	t_label	*label;

	doublon = 0;
	file->tmp_line[0][ft_strlen(file->tmp_line[0]) - 1] = '\0';
	label = file->label;
	while (label != NULL)
	{
		if (ft_strcmp(label->l_name, file->tmp_line[0]) == 0)
			doublon = 1;
		label = label->next;
	}
	if (doublon == 0)
	{
		label = ft_lstnew(file->tmp_line[0], file->file_size);
		ft_lstadd(&file->label, label);
	}
	line->has_label += 1;
	line->i++;
	if (line->has_label > 1)
	{
		exit_error("trop de label sur cette ligne.", file);
	}
	check_label_char(file);
}

void		save_size_and_label2(t_file *file, t_line *line)
{
	if (file->tmp_line[line->i])
	{
		if (file->tmp_line[0][ft_strlen(file->tmp_line[0]) - 1] == ':')
			save_label(file, line);
		if (file->tmp_line[0 + line->has_label])
			check_inst(file, line);
	}
	while (file->tmp_line[line->i])
	{
		if (file->tmp_line[line->i][0] == '#')
			break ;
		else if (file->tmp_line[line->i][0] == 'r')
		{
			file->file_size += 1;
		}
		else if (file->tmp_line[line->i][0] == DIRECT_CHAR)
		{
			file->file_size += g_op_tab[line->inst - 1].dir_size;
		}
		else if (file->tmp_line[line->i][0] != DIRECT_CHAR)
		{
			file->file_size += 2;
		}
		line->i++;
	}
}

void		save_size_and_label(t_file *file)
{
	t_line	line;
	int		i;

	while (file->file_s[file->line] != NULL)
	{
		i = 0;
		init_line(&line);
		move_to_next_line(file);
		if (file->file_s[file->line] == NULL)
			break ;
		check_label_inst(file);
		file->tmp_line = ft_strsplit(file->file_s[file->line], ' ');
		if (file->tmp_line != NULL)
			save_size_and_label2(file, &line);
		while (file->tmp_line[i])
			free(file->tmp_line[i++]);
		free(file->tmp_line);
		file->line++;
	}
}
