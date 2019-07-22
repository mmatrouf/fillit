/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:08:32 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/04/14 15:55:58 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *p;
	unsigned char *p0;

	if (n == 0)
		return (NULL);
	p = (unsigned char *)src;
	p0 = (unsigned char *)dst;
	while (n--)
	{
		if (*p == (unsigned char)c)
		{
			*p0 = *p;
			return (p0 + 1);
		}
		*p0 = *p;
		p++;
		p0++;
	}
	return (NULL);
}
