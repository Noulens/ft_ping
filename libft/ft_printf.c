/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:47:07 by tnoulens          #+#    #+#             */
/*   Updated: 2022/06/13 14:07:46 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_percentage(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

static	int	ft_print_format(int j, const char *format, va_list arg)
{
	int	i;

	i = j;
	if (*format == 'd' || *format == 'i')
		return (i += ft_di(va_arg(arg, int)));
	else if (*format == 'c')
		return (i += ft_c(va_arg(arg, int)));
	else if (*format == 'p')
		return (i += ft_p(va_arg(arg, void *)));
	else if (*format == 's')
		return (i += ft_s(va_arg(arg, char *)));
	else if (*format == 'x' || *format == 'X' || *format == 'u')
		return (i += ft_xupx(va_arg(arg, unsigned int), *format));
	else if (*format == '%')
		return (i += ft_percentage());
	else if (*format == 'l' && *(format + 1) == 'd')
		return (i += ft_ld(va_arg(arg, long)));
	else
		return (-1);
}

int	ft_print_default(int j, const char c)
{
	int i;

	i = j;
	ft_putchar_fd(c, 1);
	i += 1;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		j;

	j = 0;
	va_start(arg, format);
	while (format && *format)
	{
		while (*format != '%' && *format)
		{
			j = ft_print_default(j, *format);
			++format;
		}
		if (*format == '\0')
			return (j);
		if (*(format + 1) == 'l' && *(format + 2) == 'd')
		{
			j = ft_print_format(j, ++format, arg);
			++format;
		}
		else
			j = ft_print_format(j, ++format, arg);
		if (++format, j == -1)
			return (-1);
	}
	return (va_end(arg), j);
}

/*#include <stdio.h>

int	main(void)
{
	int		i;
	int		j;
//	int		*p;
//	char	*q;
//	char 	r[] = "FFFF";

	i = 0;
	j = 0;
//	p = &i;
//	q = NULL;
	i = ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	ft_printf("\n%d\n", i);
	j = printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	printf("\n%d\n", j);
//		i = ft_printf(" NULL %s NULL ", NULL);
//	ft_printf("\n%d\n", i);
//	j = printf(" NULL %s NULL ", NULL);
//	printf("\n%d\n", j);
	return (0);
}*/
