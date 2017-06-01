/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:09:02 by mafabre           #+#    #+#             */
/*   Updated: 2017/06/01 20:22:09 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Go to next line if # or \n
** Add space after label if inst after
** Exit_error with the line of the error.
** Without line if the error happened before opening the file.
*/

void	check_label_inst(t_file *file)
{
	file->has_name = 1;
}

void	move_to_next_line(t_file *file)
{
	while (file->file_s[file->line] && (file->file_s[file->line][0] == '\0' ||
	file->file_s[file->line][0] == '#'))
		file->line++;
	if (file->file_s[file->line] == NULL &&
			(file->has_name == 0 || file->has_comm == 0))
		exit_error("pas de nom et/ou commentaire.", file);
}

void	exit_error(char *error, t_file *file)
{
	ft_printf("Ligne %d : ", file->line + 1);
	ft_printf("%s\n", error);
	exit(0);
}

void	exit_error_nl(char *error)
{
	ft_printf("%s\n", error);
	exit(0);
}
