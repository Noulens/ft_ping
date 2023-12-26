/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:46:30 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/13 14:07:30 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenb(const char *s)
{
	register int	i;
	const char		*p;

	if (s == NULL)
		return (0);
	p = s;
	i = 0;
	while (p[i])
		++i;
	return (i);
}

char	*ft_strchrb(const char *s, int c)
{
	register const unsigned char	*p;
	int								flag;
	unsigned char					c_to_find;

	c_to_find = (unsigned char)c;
	p = (const unsigned char *)s;
	flag = 0;
	if (p)
	{
		while (*p && flag == 0)
		{
			if (*p == c_to_find)
				flag = 1;
			else
				++p;
		}
		if (flag == 1 || (c == '\0' && *p == '\0'))
			return ((char *)p);
		else
			return (NULL);
	}
	else
		return (NULL);
}

void	ft_cpy(char *suf, char *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p[i] && p[i] != '\n')
		++i;
	while (p[i])
		suf[j++] = p[++i];
}

void	*ft_callocb(size_t nmemb, size_t size)
{
	register void	*p;
	register char	*ptr;
	register size_t	mem_size;
	register size_t	max_st;

	max_st = ~(size_t)0;
	if (size > 0 && nmemb > max_st / size)
		return (NULL);
	mem_size = nmemb * size;
	p = malloc(mem_size);
	if (!p)
		return (NULL);
	ptr = p;
	while (mem_size--)
		*ptr++ = '\0';
	return (p);
}
