/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 09:03:38 by alecott           #+#    #+#             */
/*   Updated: 2018/01/17 16:10:21 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_strwlen(wchar_t *wstr)
{
	int		i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}

static int	ft_width_wchar(t_list *l, wchar_t *wstr, int i)
{
	char	*s;

	if (ft_atoi(l->width) > ft_strwlen(wstr))
	{
		s = (char*)malloc(sizeof(s) * (ft_atoi(l->width)));
		if (ft_strchr(l->flags, '0'))
			s = ft_memset(s, '0', (ft_atoi(l->width) - ft_strwlen(wstr)));
		else
			s = ft_memset(s, ' ', (ft_atoi(l->width) - ft_strwlen(wstr)));
		if (ft_strchr(l->flags, '-') == 0)
		{
			ft_putstr(s);
			i = ft_putwstr(wstr, i);
		}
		else
		{
			i = ft_putwstr(wstr, i);
			ft_putstr(s);
		}
		return (i + ft_atoi(l->width));
	}
	else
		i = ft_putwstr(wstr, i);
	return (i + ft_strwlen(wstr));
}

int			ft_conv_string(t_list *l, va_list ap, int i)
{
	wchar_t	*wstr;
	char	*str;
	char	*flag;
	int		res;

	flag = NULL;
	if (l->spec == 'S' || (ft_strequ(l->length, "l") && l->spec == 's'))
	{
		wstr = va_arg(ap, wchar_t*);
		if (wstr == NULL)
			wstr = L"(null)";
		i = ft_width_wchar(l, wstr, i);
		return (i);
	}
	else
	{
		str = va_arg(ap, char*);
		if (str == NULL)
			str = "(null)";
		str = ft_width(str, l, flag);
		ft_putstr(str);
		res = i + ft_strlen(str);
		ft_strdel(&str);
		return (res);
	}
}
