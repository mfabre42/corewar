/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:06:16 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/23 02:04:30 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Cut les quotes du nom et commentaire, check s'ils sont valides.
** Sauvegarde nom et commentaire dans leur variable respective (file->).
*/

void		check_and_cut(t_file *file)
{
	int i;
	int quote;

	i = 0;
	quote = 0;
	while (file->file_s[file->line][i])
	{
		if (file->file_s[file->line][i] == '"')
			quote++;
		i++;
	}
	if (file->file_s[file->line][i - 1] != '"')
		exit_error("erreur nom ou commentaire.", file);
	file->file_s[file->line][i - 1] = '\0';
	if (quote != 2)
		exit_error("erreur nom ou commentaire.", file);
}

void		save_name_comment(t_file *file)
{
	while (file->file_s[file->line] &&
		(file->has_name == 0 || file->has_comm == 0))
	{
		move_to_next_line(file);
		if (ft_strncmp(file->file_s[file->line], ".name ", 6) == 0)
		{
			check_and_cut(file);
			file->name = ft_strdup(&file->file_s[file->line][7]);
			file->has_name += 1;
		}
		else if (ft_strncmp(file->file_s[file->line], ".comment ", 9) == 0)
		{
			check_and_cut(file);
			file->comm = ft_strdup(&file->file_s[file->line][10]);
			file->has_comm += 1;
		}
		else
			exit_error("caractere non reconnu avant le nom et/ou commentire."
			, file);
		file->line++;
	}
	file->start = file->line;
	if (file->has_name != 1 || file->has_comm != 1)
		exit_error("erreur nom ou commentaire.", file);
}
