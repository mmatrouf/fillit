/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:18:18 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/04/21 15:01:08 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] || !needle[j])
		{
			if (!needle[j])
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
