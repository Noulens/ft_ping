/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:35:24 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/22 14:40:22 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*first;

	first = (t_list *)malloc(sizeof(t_list));
	if (!first)
		return (NULL);
	first->content = content;
	first->next = NULL;
	return (first);
}

/*#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;


int	main(void)
{
	char	s[] = "ceci";
	t_list	*ls;

	ls = ft_lstnew((char *)s);
	printf("%s", (char *)ls->content);
	return (0);
}*/
