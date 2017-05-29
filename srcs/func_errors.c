/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:49:54 by aleveque          #+#    #+#             */
/*   Updated: 2017/05/29 19:09:30 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_malloc(void)
{
	ft_printf("Erreur malloc !\n");
	exit(0);
}

void	error(int nb)
{
	if (nb == 1)
		ft_printf("Error player number\n");
	else if (nb == 2)
		ft_printf("Error player number assignement\n");
	else if (nb == 3)
		ft_printf("Error argument\n");
	else if (nb == 4)
		ft_printf("Error dump number\n");
	else if (nb == 5)
		ft_printf("Error open\n");
	else if (nb == 6)
		ft_printf("Error player len\n");
	else
		ft_printf("Error\n");
	exit(0);
}

void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-v][-d N][-s N][-n X] <champion1.cor> <...>\n\
	-d N      : Dumps memory after N cycles then exits\n\
	-s N      : Runs N cycles, dumps memory, pauses, then repeats\n\
	-n X      : Choose player number X between 0 and NUMBER OF PLAYER\n\
	-v        : Ncurses output mode (visualisateur)\n");
	exit(0);
}
