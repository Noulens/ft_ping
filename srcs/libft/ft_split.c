/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:13:12 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/25 19:27:47 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_dup(char **tofree, int i)
{
	int	k;

	k = 0;
	while (k < i)
		free(tofree[k++]);
	free(tofree);
}

static int	ft_count_word(const char *str, char c)
{
	int		word_flag;
	int		i;
	int		word_count;

	i = 0;
	word_flag = 0;
	word_count = 0;
	while (str && str[i])
	{
		if (str[i] == c)
		{
			word_flag = 0;
			++i;
		}
		else if (word_flag == 1)
			++i;
		else
		{
			word_flag = 1;
			++word_count;
			++i;
		}
	}
	return (word_count);
}

static char	*ft_strdupfill(const char *src, char c)
{
	int		lght;
	int		i;
	char	*p;

	lght = 0;
	while (*(src + lght) && *(src + lght) != c)
		++lght;
	p = (char *)malloc(lght + sizeof(char *));
	if (p == NULL)
		return (NULL);
	i = 0;
	ft_bzero(p, lght + sizeof(char *));
	while (i < lght)
	{
		*(p + i) = *(src + i);
		++i;
	}
	*(p + i) = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**spltd;
	int		nbwords;
	int		i;
	int		j;

	nbwords = ft_count_word(s, c);
	spltd = (char **)malloc(sizeof(char *) * nbwords + sizeof(char *));
	if (spltd == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < nbwords)
	{
		while (s[j] == c)
			++j;
		spltd[i] = ft_strdupfill(s + j, c);
		if (spltd[i] == NULL)
		{
			free_dup(spltd, i);
			return (NULL);
		}
		j = j + ft_strlen(spltd[i++]);
	}
	spltd[i] = 0;
	return (spltd);
}

/*#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		++i;
	return (i);
}

int	main(void)
{
	const char	s[] = "voici\tle\ttest\tultime\tde la mort\t!";
	char **tab;
	tab = ft_split(s, '\t');
	printf("%s\n", *tab);
	free(tab);
	return (0);
}*/