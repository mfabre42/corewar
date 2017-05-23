/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:40:09 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/23 20:56:00 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdlib.h>
#include "../../includes/corewar.h"

unsigned int	*init_reg(void)
{
	unsigned int	*reg;
	int				i;

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

t_process		*ft_lstnew(int start, int cycle)
{
	static unsigned int		id;
	t_process		*new;
	unsigned int	*reg;

	// printf("proc id: %d\n", id);
	if (!(new = (t_process*)malloc(sizeof(t_process))))
		return (NULL);
	if ((reg = init_reg()) == NULL)
		return (NULL);
	new->id = id;
	new->reg = reg;
	new->pc = 0;
	new->start = start;
	new->carry = 0;
	new->cycle = 0;
	new->ft = 0;
	new->do_funk = 1;
	new->last_live = cycle;
	new->next = NULL;
	id++;
	return (new);
}
