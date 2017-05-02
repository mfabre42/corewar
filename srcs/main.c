/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/02 12:28:23 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

int		main(int ac, char **av)
{
	unsigned char	*arena;
	t_params param;

	arena = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	ft_bzero(arena, MEM_SIZE);
	int i = 0;
	param = save_params(ac, av, arena);
	unsigned int qwerty;

	//init_vm(arena, param);
	qwerty = hex_to_int(0x0e, 0x68, 0x36, 0xea);
	printf("Coucou = %d\n", qwerty);
	// while (i < MEM_SIZE)
	// {
	// 	if (i % 64 == 0)
	// 		printf("\n");
	// 	printf("%02x ", arena[i]);
	// 	i++;
	// }
	return (0);
}
