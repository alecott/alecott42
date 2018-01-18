/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:40:18 by alecott           #+#    #+#             */
/*   Updated: 2018/01/17 15:04:30 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_gtfo(char *p)
{
	char	*str;
	int		i;
	int		res;

	i = 1;
	if (p[0] != '.')
		return (ft_atoi(p));
	if (!(str = (char*)malloc(sizeof(*str) * (ft_strlen(p) - 1))))
		return (0);
	while (p[i])
	{
		str[i - 1] = p[i];
		i++;
	}
	str[i - 1] = '\0';
	res = ft_atoi(str);
	ft_strdel(&str);
	return (res);
}

static char	*ft_precision_s(char *str, int i)
{
	char	*s;
	int		j;

	j = 0;
	s = (char*)malloc(sizeof(*s) * (i + 1));
	while (i > 0)
	{
		s[j] = str[j];
		j++;
		i--;
	}
	s[j] = '\0';
	return (s);
}

char		*ft_precision(char *str, t_list *l)
{
	int		i;
	char	*s;
	int		len;

	i = 0;
	s = NULL;
	if (ft_strlen(l->precision) <= 0)
		return (ft_strdup(str));
	i = ft_gtfo(l->precision);
	if (ft_strequ(str, "0") && (i == 0) && (!(ft_strchr(l->flags, '#')) ||
				!(l->spec == 'o')))
		return (s);
	len = ft_strlen(str);
	if (ft_strchr("idDXxUuOo", l->spec) && i > len)
	{
		s = (char*)malloc(sizeof(*s) * (i - len));
		s = ft_memset(s, '0', (i - len));
		str = ft_strjoin(s, str);
		ft_strdel(&s);
	}
	else if (l->spec == 's')
		str = ft_precision_s(str, i);
	else
		str = ft_strdup(str);
	return (str);
}
