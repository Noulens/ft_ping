/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:59:17 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 16:39:35 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*des;
	const char	*sc;
	size_t		n;
	size_t		dest_len;

	des = dst;
	sc = src;
	n = size;
	while (n-- != 0 && *des != '\0')
		des++;
	dest_len = des - dst;
	n = size - dest_len;
	if (n == 0)
		return (dest_len + ft_strlen(sc));
	while (*sc != '\0')
	{
		if (n != 1)
		{
			*des++ = *sc;
			n--;
		}
		sc++;
	}
	*des = '\0';
	return (dest_len + (sc - src));
}

/*#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		++i;
	return (i);
}

int	main(void)
{
char dest1[100] = "1234";
char src1[100] = "ABCD";
char dest2[100] = "1234";
char src2[100] = "ABCD";

	printf("sa fonction : %lu\n", ft_strlcat(dest1, src1, 3));
	printf("la vrai fonction : %lu\n", strlcat(dest2, src2, 3));
	printf("sa fonction : %s\n", dest1);
	printf("la vrai fonction : %s\n", dest2);
	return (0);
}*/
