/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 20:49:40 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/02 17:25:22 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void	get_n(t_params *param)
{
	if (param->p1 != 1)
	{
		param->n = 1;
		param->p1 = 1;
	}
	else if (param->p2 != 1)
	{
		param->n = 2;
		param->p2 = 1;
	}
	else if (param->p3 != 1)
	{
		param->n = 3;
		param->p3 = 1;
	}
	else if (param->p4 != 1)
	{
		param->n = 4;
		param->p4 = 1;
	}
}

void	get_name_comment(t_convert *tab, t_params *param, t_map *map, int i)
{
	t_player	tmp;
	int			j;

	j = 1;
	tmp = map->player[param->n - 1];
	i = 0;
	tmp.name = (char *)malloc(sizeof(char) * PROG_NAME_LENGTH);
	tmp.comm = (char *)malloc(sizeof(char) * COMMENT_LENGTH);
	while (j < PROG_NAME_LENGTH / 4 + 3)
	{
		tmp.name[i++] = tab[j].c_char[0];
		tmp.name[i++] = tab[j].c_char[1];
		tmp.name[i++] = tab[j].c_char[2];
		tmp.name[i++] = tab[j++].c_char[3];
	}
	i = 0;
	while (j < COMMENT_LENGTH / 4 + PROG_NAME_LENGTH / 4 + 4)
	{
		tmp.comm[i++] = tab[j].c_char[0];
		tmp.comm[i++] = tab[j].c_char[1];
		tmp.comm[i++] = tab[j].c_char[2];
		tmp.comm[i++] = tab[j++].c_char[3];
	}
	tmp.process_nbr = 1;
	tmp.process = NULL;
	map->nb_player = param->np;
	map->nb_process = param->np;
	map->player[param->n - 1] = tmp;
	printf("%s\n", tmp.name);
	printf("%s\n", tmp.comm);
}

void	check_magic_number(t_convert *tab)
{
	if (hex_to_int(tab[0].c_char[0], tab[0].c_char[1], tab[0].c_char[2],
			tab[0].c_char[3]) != 15369203)
			{
				printf("wrong magic number exit\n"); // magic number check
				exit(0);
			}
}

void	send_in_arena(t_convert *tab, t_params *param, t_map *map)
{
	int	i;
	int	j;
	int k = 0;

	if (param->n == 0)
		get_n(param);
	printf("DDDDDDD %d\n", param->n);
	i = MEM_SIZE * (param->n - 1) / param->np;
	map->player[param->n - 1].start = i;
	get_name_comment(tab, param, map, i);
	check_magic_number(tab);
	j = COMMENT_LENGTH/4 + PROG_NAME_LENGTH/4 + 4;
   // while (k < MEM_SIZE)
   // {
   // 	if (k % 64 == 0)
   // 		printf("\n");
   // 	printf("%02x ", map->arena[k]);
   // 	k++;
   // }
   map->player[param->n - 1] = init_process(map, param->n - 1, MEM_SIZE * (param->n - 1) / param->np);
	while (i < MEM_SIZE && j < COMMENT_LENGTH/4 + PROG_NAME_LENGTH/4 + CHAMP_MAX_SIZE/4 + 4)
	{
		map->arena[i++] = tab[j].c_char[0];
		map->arena[i++] = tab[j].c_char[1];
		map->arena[i++] = tab[j].c_char[2];
		map->arena[i++] = tab[j].c_char[3];
		j++;
	}
}
