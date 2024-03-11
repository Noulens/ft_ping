/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:08:40 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/13 14:07:36 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c | 32);
	else
		return (c);
}

/*#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int main()
{
    int c = ft_tolower('C');
   printf("%d", ft_tolower('C'));
   write(1, &c, 2);

    return 0;
}*/
