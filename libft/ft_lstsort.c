/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:13:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/06 16:21:18 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **begin_list, int (*cmp)(void *, void *))
{
	t_list	*ptr;
	void	*temp;

	ptr = *begin_list;
	if (!ptr)
		return ;
	while (ptr->next)
	{
		if (cmp(ptr->content, ptr->next->content) > 0)
		{
			temp = ptr->content;
			ptr->content = ptr->next->content;
			ptr->next->content = temp;
			ptr = *begin_list;
		}
		else
			ptr = ptr->next;
	}
}
