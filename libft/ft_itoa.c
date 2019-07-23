/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:23:06 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/05/05 15:00:44 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count(int n)
{
	size_t i;

	i = 0;
	if (n < 0)
		i = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	unsigned int	nb;
	size_t			len;
	char			*p;

	nb = n;
	len = ft_count(nb);
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	p[len] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		nb = n * -1;
	}
	else
		p[0] = '0';
	while (len > 0 && nb)
	{
		len--;
		p[len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (p);
}
