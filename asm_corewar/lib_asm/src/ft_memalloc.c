/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 20:10:23 by mafabre           #+#    #+#             */
/*   Updated: 2017/06/08 15:30:12 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	mem = (char *)malloc(sizeof(char) * size);
	i = 0;
	if (mem == NULL)
		exit_malloc();
	while (i < size)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
