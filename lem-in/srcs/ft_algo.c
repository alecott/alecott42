/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:06:46 by alecott           #+#    #+#             */
/*   Updated: 2018/04/25 16:59:35 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	ft_finished(int ants, t_ants *info)
{
	//determine si la fourmis est arrivee ou non
	if (ft_strequ(info->room_ant[ants - 1], info->end))
		return (1);
	return (0);
}
static void	ft_print(int ants, t_ants *info)
{
	//imprime les fourmis qui ont bouges
	write (1, "L", 1);
	ft_putnbr(ants + 1);
	write (1, "-", 1);
	ft_putstr(info->room_ant[ants]);
	write (1, " ", 1);
}

static char	*ft_take_room(char *path)
{
	//renvoie la 1er salle du path qu'on lui donne
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = 0;
	while (path[i] && path[i] != '-')
	{
		i++;
		len++;
	}
	i = 0;
	ret = (char*)malloc(sizeof(char) * (len + 1));
	while (path[i] && path[i] != '-')
	{
		ret[i] = path[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static void	ft_moove(int ants, t_ants *info)
{
	//deplace la fourmis donnee en suivant son chemin et actualise donc son path/room
	int		len;
//	char	*tmp;

	len = ft_strlen(info->path_ant[ants]);
	/*tmp = ft_strsub(info->path_ant[ants], 2, len - 2);
	ft_strdel(&info->path_ant[ants]);
	info->path_ant[ants] = ft_strdup(tmp);
	ft_strdel(tmp);*/
	info->path_ant[ants] = ft_strsub(info->path_ant[ants], 2, len - 2);
	ft_strdel(&info->room_ant[ants]);
	info->room_ant[ants] = ft_take_room(info->path_ant[ants]);
	ft_print(ants, info);
}

static void	ft_ant_path(int ants, t_ants *info)
{
	int		inutile;
	//essaye de donner le chemin(possible) le plus rapide a la fourmis
	inutile = ants + info->nb_ant;
}

void		ft_algo(t_ants *info, char **path)
{
	int		ants;
	int		over;

	path = NULL;
	over = 0;
	info->room_ant = (char**)malloc(sizeof(char*) * (info->nb_ant + 1));
	info->path_ant = (char**)malloc(sizeof(char*) * (info->nb_ant + 1));
	while (over != info->nb_ant)
	{
		ants = 0;
		while (ants < info->nb_ant)
		{
			if (info->path_ant[ants] == NULL)
				ft_ant_path(ants, info);
			else
			{
				if (ft_finished(ants, info))
					over++;
				else
					ft_moove(ants, info);
			}
			ants++;
		}
	}
}
