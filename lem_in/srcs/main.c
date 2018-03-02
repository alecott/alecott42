/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:57:46 by alecott           #+#    #+#             */
/*   Updated: 2018/03/02 16:29:23 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	ft_print(t_ants *info)
{
	int		i;

	ft_putnbr(info->nb_ant);
	write(1, "\n", 1);
	i = 0;
	while (info->rooms[i])
	{
		ft_putendl(info->rooms[i]);
		i++;
	}
	i = 0;
	while (info->tubes[i])
	{
		ft_putendl(info->tubes[i]);
		i++;
	}
}

static void	ft_mario(t_ants *info)
{
	int		i;

	i = 0;
	while (info->rooms[i])
	{
		ft_strdel(&info->rooms[i]);
		i++;
	}
	ft_memdel((void**)&info->rooms);
	i = 0;
	while (info->tubes[i])
	{
		ft_strdel(&info->tubes[i]);
		i++;
	}
	ft_memdel((void**)&info->tubes);
	i = 0;
	while ((info->names[i]))
	{
		ft_strdel((&info->names[i]));
		i++;
	}
	ft_memdel((void**)&info->names);
	ft_memdel((void**)&info->rooms_state);
}

int			main(void)
{
	t_ants	info;

	ft_bzero(&info, sizeof(t_ants));
	if (!ft_stock(&info))
	{
		ft_putstr("ERROR1");
		return (0);
	}
	ft_names(&info);
	ft_print(&info);
	if (!ft_error(&info))
	{
		ft_putstr("ERROR2");
		return (0);
	}
	write(1, "\n", 1);
	ft_BFS(&info);
	ft_mario(&info);
	return (0);
}
