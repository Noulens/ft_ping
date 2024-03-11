/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:47:00 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 16:25:35 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && *(src + i))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	if (i < size || size == 0)
	{
		while (*(src + i))
			++i;
	}
	return (i);
}

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
int c;
char dest[23];

c = ft_strlcpy(dest, "ceci est un string0", 5);
printf("Copied '%s' into '%s', size of src:%d", "ceci est un string0", dest, c);
return (0);
}*/
