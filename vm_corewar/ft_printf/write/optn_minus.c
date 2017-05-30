/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optn_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:13:01 by aleveque          #+#    #+#             */
/*   Updated: 2017/01/16 18:01:10 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_free(char *ret, char *str)
{
	char c;
	char *tmp;

	tmp = ret;
	ret = ft_strdup(ret);
	c = str[ft_findconv(str)];
	if ((c == 'd' || c == 'D' || c == 'i' || c == 'O' || c == 'u' || c == 'U'
		|| c == 'p' || c == 'x' || c == 'X' || c == 'o' || c == 'c')
		&& ft_strcmp("-9223372036854775808", ret) != 0)
		free(tmp);
	return (ret);
}

char	*optn_minus(char *str, int nbr)
{
	int		len;
	int		i;
	char	*new;

	i = -1;
	len = ft_strlen(str);
	if (len < nbr)
	{
		if (!(new = (char*)malloc(sizeof(char) * nbr + 1)))
			return (NULL);
		while (str[++i])
			new[i] = str[i];
		while (i < nbr)
			new[i++] = ' ';
		new[i] = '\0';
		free(str);
		return (new);
	}
	return (str);
}
