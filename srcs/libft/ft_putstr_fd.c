/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:34:12 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/16 12:36:23 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	char	*p;

	p = s;
	if (s)
	{
		while (*p)
		{
			ft_putchar_fd(*p, fd);
			++p;
		}
	}
}

/*#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

int	main(void)
{
	char	s[] = "Voici une chaine test \t.\n.";
	int		fd = 1;

	ft_putstr_fd(s, fd);
	return (0);
}*/