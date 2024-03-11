/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 00:24:08 by waxxy             #+#    #+#             */
/*   Updated: 2022/06/13 14:08:10 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int len, long nb)
{
	while (nb > 0)
	{
		++len;
		nb /= 10;
	}
	return (len);
}

static int	ft_ltoaleninit(long nbr)
{
	if (nbr <= 0)
		return (1);
	else
		return (0);
}

char	*ft_ltoa(long nbr)
{
	char			*res;
	int				len;
	long        	nb;

	nb = nbr;
	len = ft_ltoaleninit(nbr);
	len = ft_nblen(len, nb);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = 0;
	if (nbr == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[--len] = DECIMAL[nb % 10];
		nb /= 10;
	}
	return (res);
}
