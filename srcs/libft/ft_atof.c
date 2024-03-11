/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:31:42 by waxxy             #+#    #+#             */
/*   Updated: 2022/12/22 20:06:03 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(const char *str)
{
	float	nbr;
	float	exponent;
	int		i;
	int		sign;

	i = 0;
	nbr = (float)ft_atoi(str);
	sign = 1;
	while (str[i] != '.' && str[i])
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	exponent = 0.1;
	if (str[i])
		i++;
	while (ft_isdigit(str[i]))
	{
		nbr += (str[i] - '0') * exponent * sign;
		exponent *= 0.1;
		i++;
	}
	return (nbr);
}
