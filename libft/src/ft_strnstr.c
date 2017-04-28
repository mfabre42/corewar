/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 23:26:31 by mafabre           #+#    #+#             */
/*   Updated: 2016/03/24 19:21:53 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	leneedle;

	if (*needle == '\0')
		return ((char *)haystack);
	leneedle = ft_strlen(needle);
	while (*haystack != '\0' && len >= leneedle)
	{
		len--;
		if (*haystack == *needle && ft_memcmp(haystack, needle, leneedle) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
