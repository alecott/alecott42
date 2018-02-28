/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_BFS.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:17:45 by alecott           #+#    #+#             */
/*   Updated: 2018/02/28 13:23:29 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	ft_which_room_is_end(t_ants *info)
{
	int		i;

	i = 0;
	while (info->names[i])
	{
		if (ft_strequ(info->names[i], info->end))
			return (i);
		i++;
	}
	return (0);
}

static int	ft_which_room_is_start(t_ants *info)
{
	int		i;

	i = 0;
	while (info->names[i])
	{
		if (ft_strequ(info->names[i], info->start))
			return (i);
		i++;
	}
	return (0);
}

static void	ft_make_room_state(t_ants *info, int start)
{
	int		i;
	int		j;

	i = ft_tablen(info->names);
	j = 0;
	info->rooms_state = (int*)ft_memalloc(sizeof(int) * (i + 1));
	while (j < i)
	{
		info->rooms_state[j] = 0;
		if (j == start)
			info->rooms_state[j] = info->nb_ant;
		j++;
	}
}

void		ft_BFS(t_ants *info)
{
	int		ants;
	int		end;
	int		start;

	ants = 3;
	end = ft_which_room_is_end(info);
	start = ft_which_room_is_start(info);
	ft_make_room_state(info, start);
	ft_find_dawae(info, ants, end, start);
	/*while (info->rooms_state[end] != info->nb_ant + '0')
	{
		ants = 1;
		while (ants <= info->nb_ant)
		{
			ft_find_dawae(info, ants, end, start);
			ants++;
		}
	}
*/}
