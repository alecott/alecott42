/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 09:01:16 by alecott           #+#    #+#             */
/*   Updated: 2018/01/16 10:48:32 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_width_wchar(t_list *l, wchar_t wc, int i)
{
	char	*s;

	if (ft_atoi(l->width) > 1)
	{
		s = (char*)malloc(sizeof(s) * (ft_atoi(l->width) - 1));
		if (ft_strchr(l->flags, '0'))
			s = ft_memset(s, '0', (ft_atoi(l->width) - 1));
		else
			s = ft_memset(s, ' ', (ft_atoi(l->width) - 1));
		if (ft_strchr(l->flags, '-') == 0)
		{
			ft_putstr(s);
			i = ft_putwchar(wc, i);
		}
		else
		{
			i = ft_putwchar(wc, i);
			ft_putstr(s);
		}
		return (i + ft_atoi(l->width) - 1);
	}
	else
		i = ft_putwchar(wc, i);
	return (i);
}

int			ft_conv_char(t_list *l, va_list ap, int i)
{
	wchar_t	wc;

	if (l->spec == 'C' || (ft_strequ(l->length, "l") && l->spec == 'c'))
		wc = (wchar_t)va_arg(ap, wint_t);
	else
		wc = (unsigned char)va_arg(ap, int);
	i = ft_width_wchar(l, wc, i);
	return (i + 1);
}
