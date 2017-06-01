/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:46:38 by mafabre           #+#    #+#             */
/*   Updated: 2017/06/01 17:16:29 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Save file.s.
** Epur every tab and space in the file.s.
*/

void		free_file(t_file *file)
{
	int i;

	i = 0;
	while (file->file_s[i])
		free(file->file_s[i++]);
	free(file->file_s);
	free(file->filename);
	free(file->tmp_filename);
	free(file->name);
	free(file->comm);
	free(file->int_file);
	free(file->size_hex);
	ft_lstdel(&file->label);
}

char		*add_space(char *line, int i, int separator)
{
	char	*new_line;

	if ((line != NULL) && (line[0] == '\0' || line[0] == '.'))
		return (line);
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			separator++;
		i++;
	}
	new_line = (char *)malloc(sizeof(char) * (i + separator + 1));
	i = 0;
	separator = 0;
	while (line[i] != '\0')
	{
		new_line[separator] = line[i];
		if (line[i] == ',')
			new_line[++separator] = ' ';
		i++;
		separator++;
	}
	new_line[separator] = '\0';
	free(line);
	return (new_line);
}

char		*epur(char *str, int a, int i, char *buffer)
{
	if ((str != NULL) && (str[0] == '\0' || str[0] == '.'))
		return (str);
	if ((buffer = (char *)malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
		return (NULL);
	while (str[a] == ' ' || str[a] == '\t')
		a++;
	while (str[a] != '\0')
	{
		if ((str[a] == ' ' || str[a] == '\t') && str[a + 1] != '\0' &&
			str[a + 1] != ' ' && str[a + 1] != '\t' && str[a + 1] != ',')
		{
			buffer[i++] = ' ';
			a++;
		}
		else if (str[a] == ' ' || str[a] == '\t')
			a++;
		else
			buffer[i++] = str[a++];
	}
	while (i > 0 && (buffer[i - 1] == ' ' || buffer[i - 1] == '\t'))
		i--;
	buffer[i] = '\0';
	free(str);
	return (buffer);
}

void		save_file(char *av, t_file *file, int fd, int i)
{
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit_error_nl("Le fichier n'a pu etre ouvert.");
	while (get_next_line(fd, &line) && i++ > -1)
		free(line);
	free(line);
	close(fd);
	fd = open(av, O_RDONLY);
	(fd == -1) ? exit_error_nl("Le fichier n'a pu etre ouvert.") : 0;
	file->file_s = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (get_next_line(fd, &line))
	{
		file->file_s[i] = "";
		line = add_space(line, 0, 0);
		line = epur(line, 0, 0, "");
		file->file_s[i] = ft_strjoin(file->file_s[i], line);
		free(line);
		i++;
	}
	free(line);
	file->file_s[i] = NULL;
	close(fd);
}

int			main(int ac, char **av)
{
	int		len;
	t_file	file;

	file.line = -1;
	if (ac < 2)
		exit_error_nl("Usage : ./asm <name_champion.s>");
	if (ac > 2)
		exit_error_nl("Trop de parametres. \"./asm\" pour voir l'usage.");
	len = ft_strlen(av[1]);
	if (len < 3 || av[1][len - 2] != '.' || av[1][len - 1] != 's')
		exit_error_nl("Le fichier ne termine pas par \".s\".");
	file.tmp_filename = ft_strdup(av[1]);
	init_file_firstparse(&file);
	save_file(av[1], &file, 0, 0);
	save_name_comment(&file);
	save_size_and_label(&file);
	init_file_secondparse(&file);
	conv_file(&file);
	if (file.pc == 0)
		exit_error_nl("Aucune instructions.");
	ft_printf("%s successfully created.\n", file.filename);
	free_file(&file);
	return (0);
}
