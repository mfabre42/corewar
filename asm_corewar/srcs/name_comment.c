/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:06:16 by mafabre           #+#    #+#             */
/*   Updated: 2017/06/01 16:59:15 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Cut les quotes du nom et commentaire, check s'ils sont valides.
** Sauvegarde nom et commentaire dans leur variable respective (file->).
*/

int		check_and_cut(t_file *file, int i)
{
	int quote;
	int space;

	quote = 0;
	space = 0;
	while (file->file_s[file->line][i] == ' ' ||
			file->file_s[file->line][i] == '\t')
	{
		i++;
		space++;
	}
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
	return (space);
}

void	save_name_comment(t_file *file)
{
	int space;

	while (file->file_s[file->line] &&
		(file->has_name == 0 || file->has_comm == 0))
	{
		move_to_next_line(file);
		if (ft_strncmp(file->file_s[file->line], ".name", 5) == 0)
		{
			space = check_and_cut(file, 5);
			file->name = ft_strdup(&file->file_s[file->line][6 + space]);
			file->has_name += 1;
		}
		else if (ft_strncmp(file->file_s[file->line], ".comment", 8) == 0)
		{
			space = check_and_cut(file, 8);
			file->comm = ft_strdup(&file->file_s[file->line][9 + space]);
			file->has_comm += 1;
		}
		else
			exit_error("caractere non reconnu.", file);
		file->line++;
	}
	file->start = file->line;
	if (file->has_name != 1 || file->has_comm != 1)
		exit_error("erreur nom ou commentaire.", file);
}
