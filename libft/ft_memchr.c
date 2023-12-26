/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:13:47 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 18:24:03 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		c_to_find;

	c_to_find = (unsigned char)c;
	p = (const unsigned char *)s;
	while (n--)
	{
		if (*p == c_to_find)
			return ((void *)p);
		else
			++p;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c = 258;
	int *p;
	int	str[] = {1, 2 , 258, 4, 5};
	p = ft_memchr(str, c, 3);
    return p[0];
}*/
