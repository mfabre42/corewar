/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 22:38:12 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/31 14:36:09 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Calc and save opc.
** Check if the char separator are well formated.
** Check if the params are correct, based on their instruction.
*/

void		check_separator(t_file *file, t_line *line)
{
	if (file->tmp_line[line->i + 1])
	{
		if (file->tmp_line[line->i + 1][0] == '%' ||
			file->tmp_line[line->i + 1][0] == '-' ||
				file->tmp_line[line->i + 1][0] == 'r' ||
					file->tmp_line[line->i + 1][0] == ':' ||
						(file->tmp_line[line->i + 1][0] >= '0' &&
							file->tmp_line[line->i + 1][0] <= '9'))
		{
			file->tmp_line[line->i][ft_strlen(file->tmp_line[line->i]) - 1] =
			'\0';
			line->separator++;
		}
		else
			exit_error("nombre de parametres incorrect.", file);
	}
	else
		exit_error("caractere de separation au dernier parametre.", file);
}

void		check_params(t_file *file, t_line *line, int i)
{
	while (g_op_tab[line->inst - 1].param1_types[i])
	{
		if (line->params[0] == g_op_tab[line->inst - 1].param1_types[i])
			line->nb_params--;
		i++;
	}
	i = 0;
	while (g_op_tab[line->inst - 1].param2_types[i])
	{
		if (line->params[1] == g_op_tab[line->inst - 1].param2_types[i])
			line->nb_params--;
		i++;
	}
	i = 0;
	while (g_op_tab[line->inst - 1].param3_types[i])
	{
		if (line->params[2] == g_op_tab[line->inst - 1].param3_types[i])
			line->nb_params--;
		i++;
	}
	if (line->nb_params != 0)
		exit_error("mauvais parametre.", file);
}

void		calc_opc(t_file *file, t_line *line)
{
	int opc;

	opc = 0;
	if (g_op_tab[line->inst - 1].has_opc == 1)
	{
		if (line->params[0] == T_REG)
			opc += 64;
		if (line->params[0] == T_DIR)
			opc += 128;
		if (line->params[0] == T_IND)
			opc += 192;
		if (line->params[1] == T_REG)
			opc += 16;
		if (line->params[1] == T_DIR)
			opc += 32;
		if (line->params[1] == T_IND)
			opc += 48;
		if (line->params[2] == T_REG)
			opc += 4;
		if (line->params[2] == T_DIR)
			opc += 8;
		if (line->params[2] == T_IND)
			opc += 12;
		file->int_file[line->tmp_opc] = opc;
	}
}

void		save_opc(t_file *file, t_line *line)
{
	int i;

	i = 0;
	if (line->inst != -1 && (line->nb_params
		!= g_op_tab[line->inst - 1].nb_params
		|| line->separator + 1 != g_op_tab[line->inst - 1].nb_params))
		exit_error("parametre(s) non valide(s) pour cette instruction.", file);
	check_params(file, line, i);
	calc_opc(file, line);
}
