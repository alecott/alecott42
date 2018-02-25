/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:50:21 by alecott           #+#    #+#             */
/*   Updated: 2018/02/22 13:41:45 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	ft_search_wrong_tubes(char *str, t_ants *info)
{
	int		i;

	i = 0;
	while (info->names[i])
	{
		if (ft_strequ(str, info->names[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_error3(t_ants *info)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	while (info->tubes[i])
	{
		k = 0;
		j = 0;
		while (info->tubes[i][j] && info->tubes[i][j] != '-')
			j++;
		j++;
		while (info->tubes[i][j + k])
			k++;
		str = (char*)malloc(sizeof(char) * (k + 1));
		k = 0;
		while (info->tubes[i][j + k])
		{
			str[k] = info->tubes[i][j + k];
			k++;
		}
		str[k] = '\0';
		if (!ft_search_wrong_tubes(str, info))
			return (0);
		ft_strdel(&str);
		i++;
	}
	return (1);
}

static int	ft_error2(t_ants *info)
{
	int		i;
	int		j;
	char	*str;

	i = 0;

	while (info->tubes[i])
	{
		j = 0;
		while (info->tubes[i][j] && info->tubes[i][j] != '-')
			j++;
		str = (char*)malloc(sizeof(char) * (j + 1));
		j = 0;
		while (info->tubes[i][j] && info->tubes[i][j] != '-')
		{
			str[j] = info->tubes[i][j];
			j++;
		}
		str[j] = '\0';
		if (!ft_search_wrong_tubes(str, info))
			return (0);
		ft_strdel(&str);
		i++;
	}
	return (ft_error3(info));
}

int			ft_error(t_ants *info)
{
	int		i;
	int		n;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (info->nb_ant < 0)
		return (0);
	if (info->start == NULL || info->end == NULL)
		return (0);n = 0;
	while (info->names[i])
		i++;
	while (info->names[j])
	{
		k = 0;
		while (info->tubes[k])
		{
			if (ft_strstr(info->tubes[k], info->names[j]))
			{
				n++;
				break;
			}
			k++;
		}
		j++;
	}
	if (n != i)
		return (0);
	return (ft_error2(info));
}
