/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:08:42 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/06 16:11:26 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return ((c & 0x7f) == c);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", ft_isascii(L'¶'));
	return (0);
}*/
