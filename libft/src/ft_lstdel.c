/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:07:13 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/31 14:54:04 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

void	ft_lstdelpipe(t_list **alst)
{
	t_list	*list;
	t_list	*old;

	old = *alst;
	while (old != NULL)
	{
		list = old->pipe;
		ft_lstdelone(&old);
		old = list;
	}
	*alst = NULL;
}

void	ft_lstdel(t_list **alst)
{
	t_list	*list;
	t_list	*old;

	old = *alst;
	while (old != NULL)
	{
		ft_lstdelpipe(&old->pipe);
		list = old->next;
		ft_lstdelone(&old);
		old = list;
	}
	*alst = NULL;
}
