/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:40:09 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/02 12:14:45 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdlib.h>
#include "../../srcs/op.h"

unsigned int	*init_reg()
{
	unsigned int	*reg;
	int						i;

	i = 0;
	if (!(reg = (unsigned int*)malloc(sizeof(unsigned int) * REG_NUMBER)))
		return (NULL);
	while (i < REG_NUMBER)
	{
		reg[i] = 0;
		i++;
	}
	return (reg);
}

t_process				*ft_lstnew(int start)
{
	t_process				*new;
	static int		process_nbr = 1;
	unsigned int	*reg;

	if (!(new = (t_process*)malloc(sizeof(t_process))))
		return (NULL);
	if ((reg = init_reg()) == NULL)
		return (NULL);
	new->reg = reg;
	new->pc = start;
	new->start = start;
	new->carry = 0;
	new->cycle = 0;
	new->next = NULL;
	return (new);
}