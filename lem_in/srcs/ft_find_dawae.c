/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_dawae.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:19:12 by alecott           #+#    #+#             */
/*   Updated: 2018/03/04 13:35:57 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	ft_actuals(t_bfs *rooms, t_ants *info, char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 1;
	ft_memdel((void**)&rooms->actuals);
	rooms->actuals = (char **)malloc(sizeof(char *) * n);
	while (info->names[i])
	{
		if (ft_test2(rooms->news, info->names[i]) &&
			!ft_tabchr(rooms->olds, info->names[i]) && !ft_strequ(info->names[i], str))
		{
			rooms->actuals[n - 1] = info->names[i];
			n++;
			rooms->actuals = ft_realloc(rooms->actuals, sizeof(char *) * n, sizeof(char *) * (n + 1));
		}
		i++;
	}
	rooms->actuals[n - 1] = NULL;
}

static void	ft_olds(t_bfs *rooms, t_ants *info, char *str)
{
	char	**tmp;
	int	i;

	i = 0;
	tmp = ft_tabjoin(rooms->olds, rooms->actuals);
	while (rooms->olds[i])
	{
		ft_strdel(&(rooms->olds[i]));
		i++;
	}
	free (rooms->olds);
	rooms->olds = tmp;
	ft_actuals(rooms, info, str);
}

static void	ft_news(t_bfs *rooms, t_ants *info)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 1;
	if (rooms->news)
		ft_memdel((void**)&rooms->news);
	rooms->news = (char**)ft_memalloc(sizeof(char*) * n);
	while (rooms->actuals[i] != NULL)
	{
		j = 0;
		while (info->tubes[j])
		{
			if (ft_tubestr(info->tubes[j], rooms->actuals[i]) &&
			!(ft_test(rooms->olds, info->tubes[j])) && !(ft_tabchr(rooms->news, info->tubes[j])))
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

char		*ft_find_dawae(t_ants *info, int ants)
{
	int		i;
	int		n;
	int		x;
	char	*str;
	t_bfs	rooms;

	ft_bzero(&rooms, sizeof(t_bfs));
	str = ft_where_is_my_ant(info, ants);
	rooms.actuals = (char **)ft_memalloc(sizeof(char *) * 2);
	rooms.actuals[0] = info->names[info->nb_end];
	rooms.actuals[1] = NULL;
	rooms.olds = (char **)ft_memalloc(sizeof(char *) * 1);
	rooms.olds[0] = NULL;
	n = 0;
	x = 0;
	while (rooms.actuals && n <= ants)
	{
		i = 0;
		ft_news(&rooms, info);
		ft_olds(&rooms, info, str);
		if (x != 0)
			n++;
		while (rooms.news[i])
		{
			if (ft_tubestr(rooms.news[i], str))
			{
			if (!ft_check_ant(info, ft_link(str, rooms.news[i], info)))
					x = 1;
				else
					return (ft_link(str, rooms.news[i], info));
			}
			i++;
		}
	}
	i = 0;
	while (rooms.olds[i])
		ft_strdel(&rooms.olds[i++]);
	free(rooms.olds);
	free(rooms.actuals);
	free(rooms.news);
	return (NULL);
}
