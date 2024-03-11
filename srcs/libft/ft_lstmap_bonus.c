/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:32:25 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/22 14:50:04 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (!f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew((*f)(lst->content)));
		if (!new)
			del(new);
		lst = lst->next;
	}
	return (new);
}
