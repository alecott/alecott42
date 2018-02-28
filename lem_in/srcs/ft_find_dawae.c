/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_dawae.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:19:12 by alecott           #+#    #+#             */
/*   Updated: 2018/02/28 14:02:51 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	ft_luigi(t_bfs *rooms)
{
	int		i;

	i = 0;
//	while (rooms->olds[i])
//	{
//		ft_strdel(&rooms->olds[i]);
//		i++;
//	}
//	ft_memdel((void**)&rooms->olds);
//	i = 0;
//	while (rooms->actuals[i])
//	{
//		ft_strdel(&rooms->actuals[i]);
//		i++;
//	}
//	ft_memdel((void**)&rooms->actuals);
	ft_memdel((void**)&rooms->news);
}

static void	ft_actuals(t_bfs *rooms, t_ants *info)
{
	int		i;
	int		j;
	int		n;

	j = 0;
	i = 0;
	n = 1;
	rooms->actuals = (char **)malloc(sizeof(char *) * n);
	while (info->names[i])
	{
		if (ft_tabstr(rooms->news, info->names[i],  1) &&
			!ft_tabchr(rooms->olds, info->names[i]))
		{
			rooms->actuals[n - 1] = ft_strdup(info->names[i]);
			n++;
			rooms->actuals = ft_realloc(rooms->actuals, sizeof(char *) * n, sizeof(char *) * (n + 1));
		}
		i++;
	}
	rooms->actuals[n - 1] = NULL;
}

static void	ft_olds(t_bfs *rooms, t_ants *info)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_tabjoin(rooms->olds, rooms->actuals);
	rooms->olds = tmp;
	tmp = 0;
	ft_memdel((void **)&tmp);
	ft_actuals(rooms, info);
}

static void	ft_news(t_bfs *rooms, t_ants *info)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 1;
	rooms->news = (char**)ft_memalloc(sizeof(char*) * n);
	while (rooms->actuals[i] != NULL)
	{
		j = 0;
		while (info->tubes[j])
		{
			if (ft_strstr(info->tubes[j], rooms->actuals[i]) &&
			!(ft_tabstr(rooms->olds, info->tubes[j], 2)) && !(ft_tabchr(rooms->news, info->tubes[j])))
			{
				rooms->news[n - 1] = info->tubes[j];
				n++;
				rooms->news = ft_realloc(rooms->news, sizeof(char *) * n, sizeof(char *) * (n + 1));
				rooms->news[n - 1] = NULL;
			}
			j++;
		}
		i++;
	}
}

void		ft_find_dawae(t_ants *info, int ants, int end, int start)
{
	int		i;
	char	*str;
	t_bfs	rooms;

	i = 0;
	ft_bzero(&rooms, sizeof(t_bfs));
	str = ft_where_is_my_ant(info, ants, end, start);
	rooms.actuals = (char **)ft_memalloc(sizeof(char *) * 2);
	rooms.actuals[0] = info->names[end];
	rooms.actuals[1] = NULL;
	rooms.olds = (char **)ft_memalloc(sizeof(char *) * 1);
	rooms.olds[0] = NULL;
	while (!ft_tabchr(rooms.actuals, str))
	{
		i = 0;
		ft_putendl("\n\n\nTOUR");
		ft_news(&rooms, info);
		ft_olds(&rooms, info);
		ft_putendl("\nNEWS:");
		while (rooms.news[i])
		{
			if (i != 0)
				write(1, " ", 1);
			ft_putstr(rooms.news[i]);
			i++;
		}
		i = 0;
		ft_putendl("\nOLDS:");
		while (rooms.olds[i])
		{
			if (i != 0)
				write(1, " ", 1);
			ft_putstr(rooms.olds[i]);
			i++;
		}
		i = 0;
		ft_putendl("\nACTUALS:");
		while (rooms.actuals[i])
		{
			if (i != 0)
				write(1, " ", 1);
			ft_putstr(rooms.actuals[i]);
			i++;
		}
		ft_luigi(&rooms);
	}
}
