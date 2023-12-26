/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:09:56 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 16:22:36 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr;

	ptr = dest;
	while (n--)
		*ptr++ = *(char *)src++;
	return (dest);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
  	char src[] = "The boss";
  	char dest[] = "The noob";
    
	ft_memcpy(dest, src, 6);
	printf("%s-> %s", src, dest);
	return (0);
}*/
