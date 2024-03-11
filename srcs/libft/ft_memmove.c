/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:40:56 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/16 13:07:50 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	i = 0;
	if (!dest_ptr && !src_ptr)
		return (NULL);
	if (src_ptr < dest_ptr)
		while (++i <= n)
			dest_ptr[n - i] = src_ptr[n - i];
	else
		while (n-- > 0)
			*(dest_ptr++) = *(src_ptr++);
	return (dest);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
  	char src[] = "The boss";
  	char dest[] = "The noob";
    
	ft_memmove(dest, src, 0);
	printf("%s-> %s", src, dest);
	return (0);
}*/
