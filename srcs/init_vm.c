/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:40:57 by aleveque          #+#    #+#             */
/*   Updated: 2017/04/28 15:46:09 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_map  *init_process(t_params param, t_map new)
{
    t_player  *ret;
    t_player  *tmp;
    int       p;

    p = 1;
    while (p <= param.np)
    {
      if (!(tmp = ft_lstnew(1, param.np)))
        return (NULL);
      ft_lstaddednd(&new.process_nbr, tmp);
      p++;
    }
    return (new);
}

t_map     init_vm(unsigned char *arena, t_params param)
{
  t_map new;

  new.check = 0;
  new.nb_player = param.np;
  new.nb_process = param.np;
  new.arena = arena;
  if ((new = init_process(param, new)) == NULL)
  {  //  ERROR
    return (NULL);
  }
  return (new);
}
