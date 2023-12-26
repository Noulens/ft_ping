/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:15:38 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 16:22:56 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = c;
	return (s);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
    char	dest[50];
    char	ch = 'a';

    ft_memset(dest, ch, 50);
	printf("50 0's: %s", dest);
	return (0);
}*/