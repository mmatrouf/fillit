/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:54:45 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/05/03 23:06:52 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	while (*s)
		s++;
	if (!*s && c == '\0')
		return ((char *)s);
	s--;
	while (*s && i--)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
