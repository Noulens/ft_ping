/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:35:03 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 16:28:24 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * The strnstr() function locates the first occurrence of the null-ter‐
 *      minated string little in the string big, where not more than len
 *      characters are searched.  Characters that appear after a ‘\0’ charac‐
 *      ter are not searched.
 * RETURN VALUES
 *      If little is an empty string, big is returned; if little occurs
 *      nowhere in big, NULL is returned; otherwise a pointer to the first
 *      character of the first occurrence of little is returned.
 *
 * @param big
 * @param little
 * @param len
 * @return
 */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	l = len;
	while (*(big + i) && len--)
	{
		j = 0;
		while (*(little + j) == *(big + i + j) && (i + j) < l)
		{
			if (*(little + j + 1) == '\0')
				return ((char *)big + i);
			++j;
		}
		++i;
	}
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

int	main(void)
{

char haystack[30] = "aaabcabcd";

printf("%s:%s\n", ft_strnstr(haystack, "cd", 8), strnstr(haystack, "cd", 8));
  return (0);
}*/
