/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:18:45 by tnoulens          #+#    #+#             */
/*   Updated: 2022/05/10 13:35:07 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

/*
#include <unistd.h>

int	main(void)
{
	char	c = ';';
	int		fd = 1;

	ft_putchar_fd(c, fd);
	return (0);
}*/