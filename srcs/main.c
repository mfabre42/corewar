/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/26 21:10:40 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

int		main(int ac, char **av)
{
	t_convert	arena;

	arena = (t_convert *)malloc(sizeof(t_convert) * MEM_SIZE);
	save_params(ac, av, &arena);
	return (0);
}
