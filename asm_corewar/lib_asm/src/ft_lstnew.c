/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:40:09 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/08 15:30:57 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdlib.h>
#include "../../includes/op.h"

t_label				*ft_lstnew(char *name, int value)
{
	t_label		*new;

	if (!(new = (t_label*)malloc(sizeof(t_label))))
		exit_malloc();
	new->l_name = ft_strdup(name);
	if (new->l_name == NULL)
		exit_malloc();
	new->l_value = value;
	new->next = NULL;
	return (new);
}
