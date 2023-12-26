/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:06:58 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 16:22:27 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n && *(const char *)s1 == *(const char *)s2)
	{
		--n;
		++s1;
		++s2;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	str1[] = "A\0BCA";
	const char	str2[] = "A\0BCa";

	printf("%d", ft_memcmp(str1, str2, 5));
	return (0);
}*/
