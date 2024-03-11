/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:13:27 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/11 14:53:12 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (lst)
		return (ft_lstsize(lst->next) + 1);
	else
		return (0);
}

/*#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	*lst = new;
	new->next = temp;
	temp->next = NULL;
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
	char	s[] = "Ceci";
	char	s2[] = "Cela";

	lst = (t_list **)malloc(sizeof(t_list **));
	if (!lst)
		return (0);
	*lst = ft_lstnew(s);
	t2 = ft_lstnew(s2);
	ft_lstadd_front(lst, t2);
	printf("%d", ft_lstsize(*lst));
	return (0);

}*/