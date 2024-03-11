/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:41:13 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 16:24:11 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		length;
	int		i;
	char	*p;

	length = 0;
	while (*(s + length))
		++length;
	p = (char *)malloc(length + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(p + i) = *(s + i);
		++i;
	}
	*(p + i) = '\0';
	return (p);
}
