/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:37:34 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/04 15:19:45 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fdi(int fd, int nbr)
{
	char	*p;
	int		j;

	p = ft_itoa(nbr);
	j = ft_strlen(p);
	ft_putstr_fd(p, fd);
	if (p)
		free(p);
	return (j);
}
