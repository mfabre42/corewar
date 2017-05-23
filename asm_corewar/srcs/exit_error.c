/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:09:02 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/23 01:40:33 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Exit_error with the line of the error.
** Without line if the error happened before opening the file.
*/

void		exit_error(char *error, t_file *file)
{
	ft_printf("Ligne %d : ", file->line + 1);
	ft_printf("%s\n", error);
	exit(0);
}

void		exit_error_nl(char *error)
{
	ft_printf("%s\n", error);
	exit(0);
}
