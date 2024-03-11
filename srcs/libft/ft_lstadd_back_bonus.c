/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:13:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/06 16:21:18 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pl;

	if (lst)
	{
		if (*lst)
		{
			pl = ft_lstlast(*lst);
			pl->next = new;
		}
		else
			*lst = new;
	}
}

/*#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(char *content)
{
	t_list	*first;

	first = (t_list *)malloc(sizeof(t_list));
	if (!first)
		return (NULL);
	first->content = content;
	first->next = NULL;
	return (first);
}


int	main(void)
{
	t_list	*t2;
	t_list	**lst;
	char	s[] = "Ceci1";
	char	s2[] = "Cela";

	lst = (t_list **)malloc(sizeof(t_list **));
	if (!lst)
		return (0);
	*lst = ft_lstnew(s);
	t2 = ft_lstnew(s2);
	ft_lstadd_back(lst, t2);
	printf("%s", (char *)ft_lstlast(*lst)->content);
	return (0);
}*/