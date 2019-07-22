/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:21:43 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/04/19 20:06:43 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *r;

	if (!(r = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(r, '\0', size + 1);
	return (r);
}
