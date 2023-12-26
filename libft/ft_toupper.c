/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:37:40 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/13 14:07:34 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c & ~32);
	else
		return (c);
}

/*#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int main()
{
    int c = ft_toupper ('c');
   printf("%d", ft_toupper('c'));
   write(1, &c, 2);

    return 0;
}*/
