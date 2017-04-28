/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:40:09 by aleveque          #+#    #+#             */
/*   Updated: 2017/04/28 15:19:20 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdlib.h>
#include "../../srcs/op.h"

unsigned int	*init_reg(int player, int nb_player, int process_nbr)
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
	if (process_nbr <= nb_player)
		reg[0] = player;
	return (reg);
}

t_process				*ft_lstnew(int player, int nb_player)
{
	t_process				*new;
	static int		process_nbr = 1;
	unsigned int	*reg

	if (!(new = (t_process*)malloc(sizeof(t_process))))
		return (NULL);
	if ((reg = init_reg(player, nb_player, process_nbr)) == NULL)
		return (NULL);
	new->reg = reg;
	new->name = NULL;
	new->comm = NULL;
	new->player = player;
	new->process_nbr = process_nbr;
	new->pc = 0;
	new->start = 0;
	new->carry = 0;
	new->cycle = 0;
	new->in_life = 1;
	new->last_live = -1;
	new->next = NULL;
	process_nbr++;
	return (new);
}
