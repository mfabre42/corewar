/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:07:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/31 15:37:36 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

void	ft_lstdel(t_label **alst)
{
	t_label	*list;
	t_label	*old;

	old = *alst;
	while (old != NULL)
	{
		list = old->next;
		ft_lstdelone(&old);
		old = list;
	}
	*alst = NULL;
}
