/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_BFS.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:17:45 by alecott           #+#    #+#             */
/*   Updated: 2018/02/28 19:13:18 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

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

static void	ft_print(int ants, char *s1, char *s2, t_ants *info)
{
	int		i;
	int		j;

	ft_putstr(" s1: ");
	ft_putstr(s1);
	ft_putstr(" s2: ");
	ft_putstr(s2);
	i = ft_tablen(info->names);
	j = 0;
	while (j < i)
	{
		ft_putnbr(info->rooms_state[j]);
		j++;
	}
	write (1, " ", 1);
	write (1, "L", 1);
	ft_putnbr(ants);
	write (1, "-", 1);
	ft_putstr(s1);
	if (ants != 1)
		write (1, " ", 1);
}


static void	ft_gestion(t_ants *info, int ants, int end, int start)
{
	char	*s1;
	char	*s2;

	s1 = ft_find_dawae(info, ants, end, start);
	s2 = ft_where_is_my_ant(info, ants, end, start);
	if (info->rooms_state[ft_room_number(info, s1)] != 0 && !ft_strequ(s1, info->end))
		return;
	if (ft_strequ(s1, info->end))
		info->rooms_state[ft_room_number(info, s1)]++;
	else
		info->rooms_state[ft_room_number(info, s1)] = ants;
	if (ft_strequ(s2, info->start))
		info->rooms_state[ft_room_number(info, s2)]--;
	else
		info->rooms_state[ft_room_number(info, s2)] = info->rooms_state[ft_room_number(info, s2)] - ants;
	ft_print(ants, s1, s2, info);
}

void		ft_BFS(t_ants *info)
{
	int		ants;
	int		end;
	int		start;

	end = ft_room_number(info, info->end);
	start = ft_room_number(info, info->start);
	ft_make_room_state(info, start);
	while (info->rooms_state[end] != info->nb_ant)
	{
		ants = info->nb_ant;
		while (ants > 0)
		{
			ft_gestion(info, ants, end, start);
			ants--;
		}
		write(1, "\n", 1);
	}
}
