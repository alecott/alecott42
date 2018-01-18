/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newbloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:30:44 by alecott           #+#    #+#             */
/*   Updated: 2018/01/17 15:04:55 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_findspec(char format)
{
	char	*spec;
	int		i;

	spec = "sSpdDioOuUxXcC%";
	i = 0;
	while (spec[i])
	{
		if (format == spec[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_memlink(const char *restrict format)
{
	const char	*tmp;
	char		*str;
	int			i;

	i = 1;
	tmp = format;
	while (ft_findspec(*tmp) != 1)
	{
		tmp++;
		i++;
	}
	str = (char*)malloc(sizeof(char) * i + 1);
	str[i + 1] = '\0';
	return (str);
}

void		ft_liberez_delivrez(t_list *l)
{
	ft_strdel(&(l->content));
	ft_strdel(&(l->flags));
	ft_strdel(&(l->width));
	ft_strdel(&(l->precision));
	ft_strdel(&(l->length));
}

int			ft_newblock(const char *restrict format, t_list *l, va_list ap,
		int i)
{
	int		j;
	int		res;

	j = 0;
	format++;
	l->content = ft_memlink(format);
	while (ft_findspec(*format) != 1)
	{
		l->content[j] = *format;
		format++;
		j++;
	}
	l->content[j] = *format;
	format++;
	l = ft_lstalloc(l);
	if (ft_isspec(l, ap) == 0)
		res = 0;
	else
		res = ft_working(l, ap, i);
	ft_liberez_delivrez(l);
	return (res);
}
