/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 00:21:50 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/04/30 20:05:56 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *head;

	if (*alst && del)
	{
		while (*alst)
		{
			head = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = head;
		}
	}
}
