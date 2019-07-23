/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:42:13 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/04/17 15:03:34 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	while (s[j] == '\0' || s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (!(p = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (i <= j)
		p[k++] = s[i++];
	p[k] = '\0';
	return (p);
}
