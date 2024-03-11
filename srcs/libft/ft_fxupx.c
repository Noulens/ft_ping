/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fxupx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:03:18 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/04 15:23:21 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_hex(unsigned int addr, char *digit, int i, char c)
{
	if (c == 'x')
	{
		digit[i] = addr % 16;
		if (digit[i] < 10)
			digit[i] += 48;
		else
			digit[i] += 87;
	}
	if (c == 'X')
	{
		digit[i] = addr % 16;
		if (digit[i] < 10)
			digit[i] += 48;
		else
			digit[i] += 55;
	}
}

static int	ft_fu(int fd, unsigned int nbr)
{
	char	*p;
	int		j;

	p = ft_uitoa(nbr);
	j = ft_strlen(p);
	ft_putstr_fd(p, fd);
	if (p)
		free(p);
	return (j);
}

int	ft_fxupx(int fd, unsigned int nbr, char c)
{
	int				i;
	int				count;
	char			addr_digit[16];

	ft_bzero(addr_digit, 16);
	count = 0;
	i = 0;
	if (c == 'u')
		return (count = ft_fu(fd, nbr));
	if (nbr == 0)
	{
		ft_putchar_fd('0', fd);
		return (count = 1);
	}
	while (nbr)
	{
		ft_hex(nbr, addr_digit, i, c);
		++i;
		nbr /= 16;
	}
	count += i;
	while (--i >= 0)
		ft_putchar_fd(addr_digit[i], fd);
	return (count);
}
