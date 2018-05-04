/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_names.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:13:15 by alecott           #+#    #+#             */
/*   Updated: 2018/05/04 09:37:03 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	ft_nbrooms(t_ants *info)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (info->rooms[i])
	{
		if (info->rooms[i][0] != '#')
			len++;
		i++;
	}
	return (len);
}

static int	ft_end(t_ants *info)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	while (info->rooms[i])
	{
		if (ft_strequ(info->rooms[i], "##end"))
		{
			if (info->end != NULL)
				return (0);
			if (info->rooms[i + 1][0] != '#')
			{
				while (info->rooms[i + 1][len] != ' ')
					len++;
				info->end = ft_strsubinv(info->rooms[i + 1], len);
			}
		}
		i++;
	}
	if (info->end == NULL)
		return (0);
	return (1);
}

static int	ft_start(t_ants *info)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	while (info->rooms[i])
	{
		if (ft_strequ(info->rooms[i], "##start"))
		{
			if (info->start != NULL)
				return (0);
			if (info->rooms[i + 1][0] != '#')
			{
				while (info->rooms[i + 1][len] != ' ')
					len++;
				info->start = ft_strsubinv(info->rooms[i + 1], len);
			}
		}
		i++;
	}
	if (info->start == NULL)
		return (0);
	return (ft_end(info));
}

int			ft_names(t_ants *info)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = 0;
	len = ft_nbrooms(info);
	info->names = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	while (info->rooms[i])
	{
		len = 0;
		if (info->rooms[i][0] != '#')
		{
			while (info->rooms[i][len] != ' ')
				len++;
			info->names[j] = ft_strsubinv(info->rooms[i], len);
			j++;
		}
		i++;
	}
	info->names[j] = NULL;
	return (ft_start(info));
}
