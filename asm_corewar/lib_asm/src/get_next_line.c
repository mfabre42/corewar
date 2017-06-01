/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:13:43 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/28 18:29:19 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int		ft_find(char **line, char **stock, int *ret)
{
	int		i;
	char	*tmp;

	i = 0;
	while (stock[0][i] != '\0' && stock[0][i] != '\n')
		i++;
	if (!(*line = ft_strsub(*stock, 0, i)))
		return (-1);
	tmp = *stock;
	if (stock[0][i] != '\0' && stock[0][i + 1] != '\0')
	{
		if (!(*stock = ft_strdup(&stock[0][i + 1])))
			return (-1);
		ft_memdel((void**)&tmp);
	}
	else
	{
		*stock = NULL;
		ft_memdel((void**)&tmp);
	}
	if (*ret != 0 || ft_strlen(*line) != 0)
		*ret = 1;
	else
		free(*stock);
	return (*ret);
}

int		ft_read(const int fd, char **lie, int *ret)
{
	static char	*stock = NULL;
	char		*tmp;
	char		*buf;

	if (!(stock))
		if (!(stock = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
	if (!(buf = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	while ((ft_strchr(stock, '\n') == NULL) && *ret != 0)
	{
		*ret = read(fd, buf, BUFF_SIZE);
		buf[*ret] = '\0';
		if ((tmp = ft_strjoin(stock, buf)) == NULL)
			return (-1);
		ft_memdel((void**)&stock);
		if ((stock = ft_strdup(tmp)) == NULL)
			return (-1);
		ft_memdel((void**)&tmp);
	}
	*ret = ft_find(lie, &stock, ret);
	ft_memdel((void**)&buf);
	return (*ret);
}

int		get_next_line(const int fd, char **line)
{
	int		retour;
	char	buf[0];

	retour = 1;
	if ((read(fd, buf, 0)) == -1)
		return (-1);
	retour = ft_read(fd, line, &retour);
	return (retour);
}
