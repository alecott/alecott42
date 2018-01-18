/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 09:17:26 by alecott           #+#    #+#             */
/*   Updated: 2018/01/17 15:19:35 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include <stddef.h>

static long long	ft_length_d(t_list *l, va_list ap)
{
	long long nb;

	nb = va_arg(ap, long long);
	if (ft_strequ(l->length, "hh"))
		nb = (char)nb;
	else if (ft_strequ(l->length, "h"))
		nb = (short int)nb;
	else if (ft_strequ(l->length, "l") || l->spec == 'D')
		nb = (long int)nb;
	else if (ft_strequ(l->length, "ll"))
		nb = (long long int)nb;
	else if (ft_strequ(l->length, "j"))
		nb = (intmax_t)nb;
	else if (ft_strequ(l->length, "z"))
		nb = (size_t)nb;
	else if (ft_strequ(l->length, "t"))
		nb = (ptrdiff_t)nb;
	else
		nb = (int)nb;
	return (nb);
}

int					ft_conv_int(t_list *l, va_list ap, int i)
{
	long long	nb;
	char		*str;
	char		*tmp;
	char		*s;

	nb = ft_length_d(l, ap);
	s = NULL;
	if (nb < 0)
	{
		s = "-";
		nb = -nb;
	}
	else if (ft_strchr(l->flags, '+') && nb >= 0)
		s = "+";
	else if (ft_strchr(l->flags, ' ') && ft_strchr(l->flags, '+') == 0)
		s = " ";
	tmp = ft_llitoa_base(nb, 10);
	str = ft_width(tmp, l, s);
	ft_putstr(str);
	i = i + ft_strlen(str);
	if (tmp != str && nb >= -9223372036854775807)
		ft_strdel(&tmp);
	ft_strdel(&str);
	return (i);
}
