/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 00:31:52 by alecott           #+#    #+#             */
/*   Updated: 2018/01/17 09:54:18 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int		ft_islength(t_list *l, int i, va_list ap)
{
	int		j;

	j = 0;
	if (l->content[i] == 'j' || l->content[i] == 'z' || (l->content[i] == 'l'
				&& l->content[i + 1] != 'l') || (l->content[i] == 'h'
					&& l->content[i + 1] != 'h') || l->content[i] == 't')
	{
		l->length[j] = l->content[i];
		i++;
	}
	else if ((l->content[i] == 'l' && l->content[i + 1] == 'l') ||
			(l->content[i] == 'h' && l->content[i + 1] == 'h'))
	{
		l->length[j] = l->content[i];
		l->length[j + 1] = l->content[i + 1];
		i = i + 2;
	}
	if (!ap)
		return (0);
	if (l->content[i] != l->spec)
		return (0);
	return (1);
}

static int		ft_ispreci(t_list *l, int i, va_list ap)
{
	int		j;

	j = 0;
	if (l->content[i] == '.')
	{
		l->precision[j] = l->content[i];
		j++;
		i++;
		while ((l->content[i] >= '0' && l->content[i] <= '9'))
		{
			l->precision[j] = l->content[i];
			j++;
			i++;
		}
		if (l->content[i] == '*')
		{
			l->precision = ft_uitoa_base(va_arg(ap, int), 10);
			i++;
		}
	}
	return (ft_islength(l, i, ap));
}

static int		ft_iswidth(t_list *l, int i, va_list ap)
{
	int		j;

	j = 0;
	while ((l->content[i] >= '0' && l->content[i] <= '9'))
	{
		l->width[j] = l->content[i];
		j++;
		i++;
	}
	if (l->content[i] == '*')
	{
		l->width = ft_uitoa_base(va_arg(ap, int), 10);
		i++;
	}
	return (ft_ispreci(l, i, ap));
}

static int		ft_isflag(t_list *l, int i, va_list ap)
{
	int		j;

	j = 0;
	while (l->content[i] == '+' || l->content[i] == '-' || l->content[i] == '#'
			|| l->content[i] == '0' || l->content[i] == ' ')
	{
		l->flags[j] = l->content[i];
		j++;
		i++;
	}
	return (ft_iswidth(l, i, ap));
}

int				ft_isspec(t_list *l, va_list ap)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(l->content);
	l->spec = l->content[j - 1];
	return (ft_isflag(l, i, ap));
}
