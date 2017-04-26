/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/26 22:35:00 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

int		main(int ac, char **av)
{
	unsigned char	*arena;

	arena = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	ft_bzero(arena, MEM_SIZE);
	int i = 0;
	save_params(ac, av, arena);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printf("\n");
		printf("%02x ", arena[i]);
		i++;
	}
	return (0);
}
