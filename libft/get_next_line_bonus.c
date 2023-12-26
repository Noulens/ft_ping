/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:21:54 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/11 19:47:33 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_append(char *old, char *new)
{
	int				len;
	register char	*ptr;
	char			*ret;
	register char	*oldptr;

	if ((old == NULL && new == NULL) || new == NULL)
		return (NULL);
	oldptr = old;
	if (!old)
		len = ft_strlenb(new);
	else
		len = ft_strlenb(oldptr) + ft_strlenb(new);
	ret = (char *)malloc(len * sizeof(char) + 8);
	if (!ret)
		return (NULL);
	ft_bzero(ret, len + 8);
	ptr = ret;
	while (oldptr && *oldptr)
		*ptr++ = *oldptr++;
	while (*new)
		*ptr++ = *new++;
	*ptr = 0;
	free(old);
	return (ret);
}

static char	*ft_read(char *suf, int fd)
{
	int		n;
	char	*p;
	char	*buffy;

	n = 1;
	p = NULL;
	p = ft_append(p, suf);
	buffy = (char *)ft_callocb(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchrb(p, '\n') && n)
	{
		n = read(fd, buffy, BUFFER_SIZE);
		if (n == -1)
			return (free(buffy), free(p), NULL);
		if (n == 0)
		{
			suf[0] = 0;
			return (free(buffy), p);
		}
		buffy[n] = 0;
		p = ft_append(p, buffy);
	}
	free(buffy);
	return (p);
}

static int	ft_extract_nl(char *line)
{
	char			*p;
	register int	i;

	p = line;
	i = 0;
	while (p[i] != '\n' && p[i])
		i++;
	if (p[i] != 0)
		p[++i] = 0;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	suf[FOPEN_MAX + 1][BUFFER_SIZE + 1];
	char		*p;

	if (BUFFER_SIZE <= 0 || fd > FOPEN_MAX || fd < 0)
		return (NULL);
	p = ft_read(suf[fd], fd);
	if (p == NULL || *p == 0)
		return (free(p), NULL);
	ft_cpy(suf[fd], p);
	ft_extract_nl(p);
	return (p);
}
