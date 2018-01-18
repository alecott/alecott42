/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 02:12:07 by alecott           #+#    #+#             */
/*   Updated: 2018/01/18 13:51:36 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static char	*ft_normewidth0(t_list *l, char *flag, char *str)
{
	char	*s;
	int		y;

	y = ft_strlen(flag);
	y = ft_atoi(l->width) - ft_strlen(str) - y;
	s = (char*)malloc(sizeof(char) * y + 1);
	s = ft_memset(s, '0', y);
	return (s);
}

static char	*ft_width0(char *str, char *flag, t_list *l)
{
	char	*s;
	char	*tmp;
	char	*leaked;

	tmp = str;
	leaked = 0;
	if (ft_atoi(l->width) > ft_strlen(str))
	{
		s = ft_normewidth0(l, flag, str);
		str = ft_strjoin(s, str);
		leaked = str;
		ft_strdel(&tmp);
		ft_strdel(&s);
	}
	if (flag != NULL)
	{
		str = ft_strjoin(flag, str);
		ft_strdel(&tmp);
		if (leaked)
			ft_strdel(&leaked);
	}
	return (str);
}

static char	*ft_normewidth(t_list *l, char *str, char *s)
{
	if (str == NULL && s != NULL)
		str = s;
	else if (ft_strchr(l->flags, '-'))
		str = ft_strjoin(str, s);
	else
		str = ft_strjoin(s, str);
	return (str);
}

char		*ft_width(char *str, t_list *l, char *flag)
{
	char	*s;
	char	*tmp;

	tmp = ft_precision(str, l);
	if (ft_strchr(l->flags, '0') && ft_strlen(l->precision) == 0 &&
			!(ft_strchr(l->flags, '-')))
		return (ft_width0(tmp, flag, l));
	if (flag != NULL && (str[0] != '0' || !(ft_strequ(flag, "0"))))
		str = ft_strjoin(flag, tmp);
	else
		str = ft_strdup(tmp);
	ft_strdel(&tmp);
	if (ft_atoi(l->width) > ft_strlen(str))
	{
		s = ft_memalloc(ft_atoi(l->width) - ft_strlen(str) + 1);
		ft_memset(s, ' ', (ft_atoi(l->width) - ft_strlen(str)));
		tmp = str;
		str = ft_normewidth(l, str, s);
		if (str != s)
			ft_strdel(&s);
		ft_strdel(&tmp);
	}
	return (str);
}
