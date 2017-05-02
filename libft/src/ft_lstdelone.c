/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:55:11 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/02 12:13:42 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstdelone(t_process **alst)
{
	t_process *list;

	list = *alst;
	free(list->reg);
	free(list);
	*alst = NULL;
}
