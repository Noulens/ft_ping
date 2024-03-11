/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:19:28 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/11 20:29:10 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ptrlen(const char **ptr)
{
	size_t	i;

	i = 0;
	if (ptr == NULL)
		return (i);
	while (*(ptr + i))
		++i;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*(s + i))
		++i;
	return (i);
}

/*#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("39: %zu", ft_strlen("Moments lost in time like tears in rain"));
	return (0);
}*/
