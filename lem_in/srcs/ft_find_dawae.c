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

}

static void	ft_olds(t_bfs *rooms, t_ants *info)
{

	ft_actuals(rooms, info);
}

static void	ft_news(t_bfs *rooms, t_ants *info)
{
	int		i;
	int		j;

	i = 0;
	
	while (rooms->actuals[i])
	{
		j = 0;
		while (info->tubes[j])
		{
			
			
			j++;
		}
		i++;
	}
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
