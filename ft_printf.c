/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:08:15 by alecott           #+#    #+#             */
/*   Updated: 2018/01/17 14:54:47 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static const char	*ft_moveon(const char *restrict format)
{
	char	*spec;
	int		i;

	spec = "sSpdDioOuUxXcC%";
	while (*format != '\0')
	{
		format++;
		i = 0;
		while (spec[i])
		{
			if (*format == spec[i])
				return (format + 1);
			i++;
		}
	}
	return (format);
}

int					ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_list		*l;
	static int	i;

	i = 0;
	va_start(ap, format);
	l = (t_list*)malloc(sizeof(t_list));
	while (*format != '\0')
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			format++;
			i++;
		}
		else if (*format == '%')
		{
			i = ft_newblock(format, l, ap, i);
			format = ft_moveon(format);
		}
	}
	free(l);
	va_end(ap);
	return (i);
}
