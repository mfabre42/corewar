/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:30:21 by mafabre           #+#    #+#             */
/*   Updated: 2017/05/31 18:27:35 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		p;
	char	**split;

	i = 0;
	k = 0;
	if (!(split = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0' && k < ft_count_word(s, c))
	{
		j = 0;
		p = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		split[k] = (char *)malloc(sizeof(char) * (j + 1));
		while (j > p)
			split[k][p++] = s[i++];
		split[k++][p] = '\0';
	}
	split[k] = NULL;
	return (split);
}
