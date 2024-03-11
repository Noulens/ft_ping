/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:59:32 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/10 15:14:27 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		++nptr;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		++nptr;
	}
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - 48;
		++nptr;
	}
	return (sign * result);
}

long long	ft_capped_atoll(const char *nptr, int *status)
{
	int			sign;
	long long	result;

	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		++nptr;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		++nptr;
	}
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (sign > 0 && (LLONG_MAX - *nptr + '0') / 10 < result)
			return (++*status, 0);
		if (sign < 0 && (LLONG_MIN + *nptr - '0') / 10 > -result)
			return (++*status, 0);
		result = 10 * result + *nptr - '0';
		nptr++;
	}
	return (sign * result);
}
