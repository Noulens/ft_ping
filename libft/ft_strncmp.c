/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:35:48 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/17 12:53:28 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	else if ((s1 == NULL && s2) || (s1 && s2 == NULL))
		return (-1);
	else
	{
		while (*s1 && (*s1 == *s2))
		{
			++s1;
			++s2;
		}
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
}

int	ft_cmpchr(const char *s1, const char *s2, char c)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	else if ((s1 == NULL && s2) || (s1 && s2 == NULL))
		return (-1);
	else
	{
		while (*s1 && (*s1 == *s2) && *(s1 + 1) != c)
		{
			++s1;
			++s2;
		}
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	else if ((s1 == NULL && s2) || (s1 && s2 == NULL))
		return (-1);
	else
	{
		while (n && *s1 && (*s1 == *s2))
		{
			++s1;
			++s2;
			--n;
		}
		if (n == 0)
			return (0);
		else
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	s1[] = {"aa "};
	char	s2[] = {"aa~"};

	printf("%d", ft_strncmp(s1, s2, 3510));
	return (0);
}*/
