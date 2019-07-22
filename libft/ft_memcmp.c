/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:40:50 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/04/14 15:54:51 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *p;
	unsigned char *p0;

	p = (unsigned char *)s1;
	p0 = (unsigned char *)s2;
	while (n--)
	{
		if (*p != *p0)
			return (*p - *p0);
		p++;
		p0++;
	}
	return (0);
}
