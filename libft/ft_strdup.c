/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:24:00 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/05/03 22:59:10 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	str = (char*)malloc((j + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < j)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
