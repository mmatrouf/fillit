/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 23:10:00 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/05/03 22:36:41 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *p;
	unsigned char *p0;

	p = (unsigned char *)src;
	p0 = (unsigned char *)dst;
	while (n--)
	{
		*p0 = *p;
		p++;
		p0++;
	}
	return (dst);
}
