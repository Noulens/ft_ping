/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:21:24 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 18:24:12 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*p;
	int					flag;
	unsigned char		c_to_find;

	c_to_find = (unsigned char)c;
	p = (const unsigned char *)s;
	flag = 0;
	while (*p && flag == 0 && *p != ' ')
	{
		if (*p == c_to_find)
			flag = 1;
		else
			++p;
	}
	if (flag == 1 || (c == '\0' && *p == '\0'))
		return ((char *)p);
	else
		return (NULL);
}

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c = '\0';
	char	str[] = "ABCD";
	printf("%p, %p", ft_strchr(str, c), &str[4]);
    return 0;
}*/
