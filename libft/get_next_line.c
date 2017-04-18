/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:39:25 by mafabre           #+#    #+#             */
/*   Updated: 2016/09/30 14:09:32 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	free_join(char **line, char *sub_line)
{
	char	*tmp_line;

	tmp_line = *line;
	*line = ft_strjoin(tmp_line, sub_line);
	free(tmp_line);
}

static int	tmp_join(t_static *var, char *sub_line, char **line)
{
	int		lenght_an;
	int		lenght_bn;
	char	*tmp_subline;

	lenght_an = ft_strlen(ft_strchr(sub_line, '\n'));
	lenght_bn = ft_strlen(sub_line) - lenght_an;
	tmp_subline = ft_strsub(sub_line, 0, lenght_bn);
	var->tmp = ft_strsub(sub_line, lenght_bn + 1, lenght_an);
	free_join(line, tmp_subline);
	free(tmp_subline);
	free(sub_line);
	return (1);
}

static void	join_sub_line(t_static *var, char **sub_line)
{
	*sub_line = ft_strjoin(var->tmp, *sub_line);
	var->tmp = NULL;
}

int			get_next_line(const int fd, char **line)
{
	static t_static	var;
	char			*sub_line;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strdup("");
	var.ret = 1;
	while (var.ret > 0)
	{
		sub_line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		var.ret = read(fd, sub_line, BUFF_SIZE);
		sub_line[var.ret] = '\0';
		if (var.tmp != NULL)
			join_sub_line(&var, &sub_line);
		if (ft_strchr(sub_line, '\n') != NULL)
			return (tmp_join(&var, sub_line, line));
		else
			free_join(line, sub_line);
		free(sub_line);
	}
	if (var.ret == 0 && (var.end)++ == 0 && *line[0] != '\0')
		return (1);
	if (var.ret == 0)
		return (0);
	return (-1);
}
