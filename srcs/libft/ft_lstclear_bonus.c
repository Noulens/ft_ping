/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:50:29 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/13 19:20:12 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = tmp;
	}
	lst = NULL;
}

/*#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

void	delf(void *stuff)
{
	free(stuff);
}

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
	char	*s;
	char	*s2;
	void	(*del)(void *);

	s = malloc(sizeof(char) * 4 + 1);
	s2 = malloc(sizeof(char) * 4 + 1);
	s[0] = 'C'; s[1] = 'e'; s[2] = 'c'; s[3] = 'i'; s[4] = '\0';
	s2[0] = 'C'; s2[1] = 'e'; s2[2] = 'c'; s2[3] = 'i'; s2[4] = '\0';
	del = &delf;
	lst = (t_list **)malloc(sizeof(t_list **));
	if (!lst)
		return (0);
	*lst = ft_lstnew(s);
	t2 = ft_lstnew(s2);
	ft_lstadd_back(lst, t2);
	printf("%s", (char *)ft_lstlast(*lst)->content);
	ft_lstclear(lst, del);
	return (0);
}*/
