/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:08:38 by tnoulens          #+#    #+#             */
/*   Updated: 2022/09/22 13:56:42 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_supercat(char *p, const char *s1, const char *s2, char *sep)
{
	while (*s1)
		*p++ = *s1++;
	while (*sep)
		*p++ = *sep++;
	while (*s2)
		*p++ = *s2++;
	*p = 0;
}

char	*ft_strjoinsep(char const *s1, char const *s2, char *sep)
{
	int		len;
	int		len_sep;
	char	*sct;
	char	*p;

	len = ft_strlen(s1) + ft_strlen(s2);
	len_sep = ft_strlen(sep);
	sct = (char *)malloc(sizeof(char) * len + len_sep + 1);
	if (!sct)
		return (NULL);
	p = sct;
	ft_supercat(p, s1, s2, sep);
	return (sct);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*p;
	char	*char_ptr;

	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	char_ptr = p;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = 0;
	return (char_ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	s1[] = "test";
	char	s2[] = "okay";
	char	*p;

	printf("%s", p = ft_strjoinsep(s1, s2, "\t\n\v\f\r"));
	free(p);
	return (0);
}*/

/*#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	printf("./ex03/output___said___this___is___a___success :\n");
	printf("%s\n",  ft_strjoin(argc, argv, "___"));
}*/
