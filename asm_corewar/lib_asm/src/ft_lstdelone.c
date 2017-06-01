/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:55:11 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/31 15:38:35 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstdelone(t_label **alst)
{
	t_label *list;

	list = *alst;
	free(list->l_name);
	free(list);
	*alst = NULL;
}
