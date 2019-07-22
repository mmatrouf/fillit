/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 16:52:37 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/04/25 19:33:50 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countwrd(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			i++;
			s++;
		}
		if (i)
			j++;
		i = 0;
	}
	return (j);
}

static int		wrdlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char		*ft_fill(char **p, char const *s, int cell, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		p[cell][i] = *s;
		s++;
		i++;
	}
	p[cell][i] = '\0';
	return ((char *)s);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**p;
	int		wnmbr;
	int		cell;
	int		len;

	len = 0;
	cell = 0;
	if (!s)
		return (NULL);
	wnmbr = countwrd(s, c);
	if (!(p = (char **)malloc(sizeof(char *) * (wnmbr + 1))))
		return (NULL);
	while (cell < wnmbr && *s)
	{
		while (*s == c)
			s++;
		len = wrdlen(s, c);
		if (!(p[cell] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		s = ft_fill(p, s, cell, len);
		cell++;
	}
	p[cell] = 0;
	return (p);
}
