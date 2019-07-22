/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:06:03 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/04/21 16:52:30 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[i])
	{
		while ((haystack[i + j] == needle[j] || !needle[j]) && (i + j) <= len)
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
