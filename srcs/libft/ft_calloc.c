/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:30:48 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/08 15:42:21 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	mem_size;
	size_t	max_st;

	max_st = ~(size_t)0;
	if (size > 0 && nmemb > max_st / size)
		return (NULL);
	mem_size = nmemb * size;
	p = malloc(mem_size);
	if (!p)
		return (NULL);
	ft_bzero(p, mem_size);
	return (p);
}
