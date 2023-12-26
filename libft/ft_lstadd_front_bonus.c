/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:40:17 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/11 19:58:30 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
	*lst = new;
	}
}

/*#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


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
	free(lst);
	free(t2->next);
	free(t2);
	return (0);

}*/
