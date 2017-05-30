/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:07:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/02 13:01:02 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

void	ft_lstdel(t_process **alst)
{
	t_process	*list;
	t_process	*old;

	old = *alst;
	while (old != NULL)
	{
		list = old->next;
		ft_lstdelone(&old);
		old = list;
	}
	*alst = NULL;
}
