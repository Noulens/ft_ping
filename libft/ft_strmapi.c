/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:21:00 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 16:26:07 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;
	int		lgth;

	if (!s || !f)
		return (NULL);
	i = 0;
	lgth = ft_strlen(s);
	res = (char *)malloc(lgth * sizeof(char) + sizeof(char));
	if (!res)
		return (NULL);
	while (i < lgth)
	{
		res[i] = (*f)(i, s[i]);
		++i;
	}
	res[i] = 0;
	return (res);
}

/*#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		++i;
	return (i);
}

char	ft_toupperi(unsigned int nb, char c)
{
	if (c >= 'a' && c <= 'z' && nb >= 1)
		return (c & ~32);
	else if (nb >= 1)
		return (c);
	else
		return (0);
}

int	main(void)
{
	char const	tab[] = "aaaa aa..";
	char		(*ptr)(unsigned int, char);
	char		*p;

	ptr = &ft_toupperi;
	p = ft_strmapi(tab, *ptr);
	printf("%s", p);
	free(p);
	return (0);
}*/