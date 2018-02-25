/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_dawae.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:19:12 by alecott           #+#    #+#             */
/*   Updated: 2018/02/25 17:48:25 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	ft_luigi(t_bfs *rooms)
{
	int		i;

	i = 0;
	while (rooms->olds[i])
	{
		ft_strdel(&rooms->olds[i]);
		i++;
	}
	ft_memdel((void**)&rooms->olds);
	i = 0;
	while (rooms->actuals[i])
	{
		ft_strdel(&rooms->actuals[i]);
		i++;
	}
	ft_memdel((void**)&rooms->actuals);
	i = 0;
	while ((rooms->news[i]))
	{
		ft_strdel((&rooms->news[i]));
		i++;
	}
	ft_memdel((void**)&rooms->news);
}

static void	ft_actuals(t_bfs *rooms, t_ants *info)
{
	int		i;

	i = 0;
	while (rooms->news[i])
	{
		
		i++;
	}
}

static void	ft_olds(t_bfs *rooms, t_ants *info)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_tabjoin(rooms->olds, rooms->actuals);
	while (rooms->olds[i])
	{
		ft_strdel(&rooms->olds[i]);
		i++;
	}
	ft_memdel((void**)rooms->olds);
	rooms->olds = tmp;
	while (tmp[i])
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	ft_memdel((void**)tmp);
	ft_actuals(rooms, info);
}

static void	ft_news(t_bfs *rooms, t_ants *info)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 1;
	rooms->actuals = (char**)ft_memalloc(sizeof(char*) * n);
	while (rooms->actuals[i])
	{
		j = 0;
		while (info->tubes[j])
		{
			if (ft_strstr(info->tubes[j], rooms->actuals[i]) &&
			!(ft_tabstr(rooms->olds, info->tubes[j], 2) &&
			!(ft_tabstr(rooms->actuals, info->tubes[j], 2))))
			{
				rooms->actuals[n - 1] = info->tubes[j];
				n++;
				rooms->actuals = ft_realloc(rooms->actuals, n, n + 1);
			}
			j++;
		}
		i++;
	}
	rooms->actuals[n] = NULL;
	ft_olds(rooms, info);
}

void		ft_find_dawae(t_ants *info, int ants, int end, int start)
{
	int		i;
	char	*str;
	t_bfs	rooms;

	i = 0;
	ft_bzero(&info, sizeof(t_bfs));
	str = ft_strdup(ft_where_is_my_ant(info, ants, end, start));
	rooms.actuals = (char **)ft_memalloc(sizeof(char *) * 2);
	rooms.actuals[0] = info->names[end];
	rooms.actuals[1] = NULL;
	while (rooms.actuals)
	{
		/*if ()
		{
			str = "?";
			ft_print_datshit(str);
		}*/
		ft_luigi(&rooms);
		ft_news(&rooms, info);
	}
}
