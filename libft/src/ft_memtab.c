/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:36:55 by mafabre           #+#    #+#             */
/*   Updated: 2016/10/01 01:52:46 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

char	**ft_memtab(char **tab, char *newline)
{
	int		i;
	char	**new_tab;

	i = 0;
	while (tab[i])
		i++;
	new_tab = (char **)malloc(sizeof(char *) * (i + 1) + 1);
	i = 0;
	while (tab[i])
	{
		new_tab[i] = (char *)malloc(sizeof(char) * ft_strlen(tab[i] + 1));
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = (char *)malloc(sizeof(char) * ft_strlen(newline + 1));
	new_tab[i] = newline;
	new_tab[i + 1] = NULL;
	free(tab);
	return (new_tab);
}
