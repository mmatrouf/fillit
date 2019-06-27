/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:01:59 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/04/30 20:21:57 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *flst;
	t_list *pflst;

	if (lst && f)
	{
		flst = f(lst);
		pflst = flst;
		while (lst->next)
		{
			flst->next = f(lst->next);
			lst = lst->next;
			flst = flst->next;
		}
		return (pflst);
	}
	else
		return (NULL);
}
