/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_in_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:56:41 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/31 19:03:57 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Conv in hex.
** Save data in filename.cor.
*/

void		write_header(t_file *file, int fd)
{
	t_convert *convert;

	if (!(convert = (t_convert *)malloc(sizeof(t_convert) * 1)))
		exit_error_nl("Erreur de malloc.");
	convert[0].c_int = file->header.prog_size;
	write(fd, (char *)&convert[0].c_char[3], 1);
	write(fd, (char *)&convert[0].c_char[2], 1);
	write(fd, (char *)&convert[0].c_char[1], 1);
	write(fd, (char *)&convert[0].c_char[0], 1);
	free(convert);
}

void		write_name_comment(t_file *file, int fd)
{
	size_t	i;

	i = 0;
	file->header.prog_size = file->pc;
	while (i < PROG_NAME_LENGTH + 4)
	{
		if (i > ft_strlen(file->name))
			file->header.prog_name[i] = '\0';
		else
			file->header.prog_name[i] = file->name[i];
		write(fd, (char *)&file->header.prog_name[i], 1);
		i++;
	}
	write_header(file, fd);
	i = 0;
	while (i < COMMENT_LENGTH + 4)
	{
		if (i > ft_strlen(file->comm))
			file->header.comment[i] = '\0';
		else
			file->header.comment[i] = file->comm[i];
		write(fd, (char *)&file->header.comment[i], 1);
		i++;
	}
}

void		write_magic_number(t_file *file, int fd)
{
	t_convert *convert;

	if (!(convert = (t_convert *)malloc(sizeof(t_convert) * 1)))
		exit_error_nl("Erreur de malloc.");
	convert[0].c_int = 15369203;
	write(fd, (char *)&convert[0].c_char[3], 1);
	write(fd, (char *)&convert[0].c_char[2], 1);
	write(fd, (char *)&convert[0].c_char[1], 1);
	write(fd, (char *)&convert[0].c_char[0], 1);
	free(convert);
	write_name_comment(file, fd);
}

int			write_program(t_file *file, t_convert *convert, int fd, int i)
{
	if (file->size_hex[file->int_i] == 1)
	{
		write(fd, (char *)&convert[i].c_char[0], 1);
	}
	else if (file->size_hex[file->int_i] == 2)
	{
		write(fd, (char *)&convert[i].c_char[1], 1);
		write(fd, (char *)&convert[i].c_char[0], 1);
	}
	else if (file->size_hex[file->int_i] == 4)
	{
		write(fd, (char *)&convert[i].c_char[3], 1);
		write(fd, (char *)&convert[i].c_char[2], 1);
		write(fd, (char *)&convert[i].c_char[1], 1);
		write(fd, (char *)&convert[i].c_char[0], 1);
	}
	return (i);
}

void		conv_in_hex(t_file *file)
{
	int			fd;
	int			i;
	t_convert	*convert;

	fd = 0;
	i = 0;
	if (!(convert = (t_convert *)malloc(sizeof(t_convert) * file->int_i +
		PROG_NAME_LENGTH + COMMENT_LENGTH + 1)))
		exit_error_nl("Erreur de malloc.");
	if (ft_strlen(file->name) > 128 || ft_strlen(file->comm) > 2048)
		exit_error_nl("Nom ou commentaire trop long.");
	file->tmp_filename[ft_strlen(file->tmp_filename) - 2] = '\0';
	file->filename = ft_strjoin(file->tmp_filename, ".cor");
	if (!(fd = open(file->filename,
				O_WRONLY | O_CREAT | O_TRUNC, 0644)))
		exit_error_nl("La creation du fichier .cor a echoue.");
	file->int_i = 0;
	write_magic_number(file, fd);
	while (file->size_hex[file->int_i] != 0)
	{
		convert[i].c_int = file->int_file[file->int_i];
		i = write_program(file, convert, fd, i);
		file->int_i++;
	}
	free(convert);
}
