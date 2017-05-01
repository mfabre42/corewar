/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:40:57 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/01 21:44:14 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_map  *init_process(t_player *player, int start, t_params param)
{
    t_player  *tmp;

///while nb_process;
    if (!(tmp = ft_lstnew(1, param.np)))
      return (NULL);
    ft_lstaddend(&new.process_nbr, tmp);
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
//  init_player();
  return (new);
}
