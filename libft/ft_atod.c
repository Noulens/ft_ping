/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:34:14 by waxxy             #+#    #+#             */
/*   Updated: 2022/12/21 14:34:44 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	double	nbr;
	double	exponent;
	int		i;

	nbr = (double)ft_atoi(str);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	exponent = 0.1;
	if (str[i])
		i++;
	while (ft_isdigit(str[i]))
	{
		nbr += (str[i] - '0') * exponent;
		exponent *= 0.1;
		i++;
	}
	return (nbr);
}
