/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:23:36 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 16:27:07 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*p;
	unsigned char		c_to_find;
	int					s_len;

	p = (const unsigned char *)s;
	c_to_find = (unsigned char)c;
	s_len = ft_strlen(s);
	if (c_to_find == '\0' && *(p + s_len) == '\0')
		return ((char *)p + s_len);
	while (s_len--)
	{
		if (*(p + s_len) == c_to_find)
			return ((char *)p + s_len);
	}
	return (NULL);
}

/*#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		++i;
	return (i);
}

int main()
{
	int c = 'D';
	char	str[] = "DABC";
	printf("%p, %p", ft_strrchr(str, c), &str[0]);
    return 0;
}*/
