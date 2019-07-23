/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:20:08 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/04/25 19:51:30 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *ds;
	char *sr;

	ds = (char *)dst;
	sr = (char *)src;
	if (dst < src)
		ft_memcpy(ds, sr, len);
	else
		while (len--)
			ds[len] = sr[len];
	return (ds);
}
