/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:47:07 by tnoulens          #+#    #+#             */
/*   Updated: 2022/10/04 15:31:08 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fpercentage(int fd)
{
	ft_putchar_fd('%', fd);
	return (1);
}

static	int	ft_fprint_format(int fd, const char *format, va_list arg)
{
	int	j;

	j = 0;
	if (*format == 'd' || *format == 'i')
		return (j = ft_fdi(fd, va_arg(arg, int)));
	else if (*format == 'c')
		return (j = ft_fc(fd, va_arg(arg, int)));
	else if (*format == 'p')
		return (j = ft_fp(fd, va_arg(arg, void *)));
	else if (*format == 's')
		return (j = ft_fs(fd, va_arg(arg, char *)));
	else if (*format == 'x' || *format == 'X' || *format == 'u')
		return (j = ft_fxupx(fd, va_arg(arg, unsigned int), *format));
	else if (*format == '%')
		return (j = ft_fpercentage(fd));
	else
		return (-1);
}

int	ft_fprint_default(int fd, char c)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	arg;
	int		j;
	int		error;

	j = 0;
	va_start(arg, format);
	while (format && *format)
	{
		while (*format != '%' && *format)
		{
			j += ft_fprint_default(fd, *format);
			++format;
		}
		if (*format == '\0')
			return (j);
		else
			error = ft_fprint_format(fd, ++format, arg);
		if (error == -1)
			return (-1);
		else
			j += error;
		++format;
	}
	va_end(arg);
	return (j);
}
