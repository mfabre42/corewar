/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 22:10:08 by mafabre           #+#    #+#             */
/*   Updated: 2016/09/14 15:38:42 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_static
{
	int		ret;
	int		end;
	char	*tmp;
}				t_static;

int				get_next_line(const int fd, char **line);

#endif
