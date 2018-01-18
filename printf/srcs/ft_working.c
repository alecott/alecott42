/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_working.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 05:03:15 by alecott           #+#    #+#             */
/*   Updated: 2018/01/17 13:02:53 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_conv_p(t_list *l, va_list ap, int i)
{
	char		*str;
	char		*flag;
	char		*tmp;
	long int	nb;

	flag = "0x";
	nb = va_arg(ap, long int);
	tmp = ft_uitoa_base(nb, 16);
	str = ft_width(tmp, l, flag);
	ft_putstr(str);
	if (tmp != str)
		ft_strdel(&tmp);
	i = i + ft_strlen(str);
	ft_strdel(&str);
	return (i);
}

static int	ft_conv(t_list *l, int i)
{
	char	*str;
	char	*flag;
	int		res;

	flag = NULL;
	str = "%";
	if (l->content)
		flag = NULL;
	str = ft_width(str, l, flag);
	ft_putstr(str);
	res = i + ft_strlen(str);
	ft_strdel(&str);
	return (res);
}

int			ft_working(t_list *l, va_list ap, int i)
{
	if (l->spec == 'd' || l->spec == 'i' || l->spec == 'D')
		return (ft_conv_int(l, ap, i));
	else if (l->spec == 'o' || l->spec == 'u' || l->spec == 'U' ||
			l->spec == 'O' || l->spec == 'x' || l->spec == 'X')
		return (ft_conv_octal(l, ap, i));
	else if (l->spec == 'c' || l->spec == 'C')
		return (ft_conv_char(l, ap, i));
	else if (l->spec == 's' || l->spec == 'S')
		return (ft_conv_string(l, ap, i));
	else if (l->spec == 'p')
		return (ft_conv_p(l, ap, i));
	else if (l->spec == '%')
		return (ft_conv(l, i));
	return (0);
}
