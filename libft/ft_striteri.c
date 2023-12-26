/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:54:54 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 16:14:11 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
	return ;
}

/*#include <unistd.h>
#include <stdio.h>

void	ft_touppera(unsigned int i, char *c)
{
	if (*(c + i) >= 'a' && *(c + i) <= 'z')
		*(c + i) = (*(c + i) & ~32);
	return ;
}

void	iter(unsigned int i, char * s)
{
    *s += i;
}

int	main(void)
{
	char	tab[] = "0000000000";
	void	(*ptr)(unsigned int, char*);

	ptr = &iter;
	ft_striteri(tab, *ptr);
	printf("%s", tab);
	return (0);
}*/