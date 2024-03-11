/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_vect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:37:50 by waxxy             #+#    #+#             */
/*   Updated: 2023/01/24 13:37:54 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_zero(int prec, int fd, int mode)
{
	int	i;

	i = 0;
	if (prec == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (mode == 0)
	{
		write(fd, "0.", 2);
		while (i++ < prec)
			write(fd, "0", 1);
	}
	else
	{
		write(fd, "0.", 2);
		while (i++ < prec - 1)
			write(fd, "0", 1);
		ft_putnbr_fd(mode, fd);
	}
}

static int	ft_nblen(int len, unsigned long nb)
{
	while (nb > 0)
	{
		++len;
		nb /= 10;
	}
	return (len);
}

static void	ft_putter(long n, int prec, int fd)
{
	int		i;
	char	tab[52];

	if (n == 0)
		return (put_zero(prec, fd, 0), (void)0);
	i = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (ft_nblen(0, n) == 1)
		return (put_zero(prec, fd, n), (void)0);
	if (ft_nblen(0, n) <= prec)
		write(fd, "0", 1);
	while (n > 0)
	{
		tab[i++] = n % 10 + 48;
		if (i == prec)
			tab[i++] = '.';
		n /= 10;
	}
	while (--i >= 0)
		write(fd, &tab[i], 1);
}

static int	ft_recursive_power(int n, int power)
{
	if (power < 0)
		return (0);
	if ((power == 0 && n == 0) || power == 0)
		return (1);
	return (ft_recursive_power(n, power - 1) * n);
}

void	ft_putfloat_fd(float x, int precision, int fd)
{
	long	n;
	int		pow;
	int		len;

	pow = ft_recursive_power(10, precision);
	x *= pow;
	if (x > 2147483647.0f * pow || x < -2147483648.0f * pow)
		return (write(2, "overflow\n", 9), (void)0);
	else
	{
		n = (long)x;
		len = ft_nblen(0, n);
		if (len > 50)
			return (write(2, "overflow\n", 9), (void)0);
		ft_putter(n, precision, fd);
	}
}
/*
#include <unistd.h>


int	main(void)
{
	ft_putfloat_fd(0.0f, 3, 1);
	return (0);
}*/
