/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:23:23 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/16 14:17:44 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_setbase(char **p, int base)
{
	if (*p == NULL)
	{
		if (base == 16)
			*p = HEX;
		else if (base == 2)
			*p = BINARY;
		else if (base == 8)
			*p = OCT;
	}
}

static int	ft_in_base(char c, char *base, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if (c == base[i])
			return (i);
		++i;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int		i;
	int		strlen;
	long	result;
	char	*b;

	i = 0;
	b = NULL;
	if (str == NULL)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	strlen = ft_strlen(str + i);
	if (strlen >= 2 && str[i] == '0' && (ft_tolower(str[i + 1]) == 'b'
			|| ft_tolower(str[i + 1]) == 'x'))
		i += 2;
	else if (strlen >= 3 && str[i] == '0'
		&& str[i + 1] == 3 && str[i + 2] == '3')
		i += 3;
	result = 0;
	ft_setbase(&b, base);
	while (str[i] != 0 && str[i] != '\n')
		result = result * base + ft_in_base(ft_tolower(str[i++]), b, base);
	return (result);
}
