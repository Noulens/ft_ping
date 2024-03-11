/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:51:31 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/16 17:37:25 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c <= 126 && c >= 32);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", ft_isprint(32));
	return (0);
}*/
