/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:42:17 by mafabre           #+#    #+#             */
/*   Updated: 2016/04/02 19:01:03 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_strlen(s);
	k = 0;
	while (s[j - 1] == '\t' || s[j - 1] == ' ' || s[j - 1] == '\n')
		j--;
	while ((s[i] == '\t' || s[i] == ' ' || s[i] == '\n') && j > 0)
	{
		i++;
		j--;
	}
	trim = (char *)malloc(sizeof(char) * j + 1);
	if (trim == NULL)
		return (NULL);
	while (j > k)
		trim[k++] = s[i++];
	trim[k] = '\0';
	return (trim);
}
