/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:06:46 by alecott           #+#    #+#             */
/*   Updated: 2018/04/27 17:01:19 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	ft_finished(int ants, t_ants *info)
{
	//determine si la fourmis est arrivee ou non
	if (ft_strequ(info->room_ant[ants], info->end))
	{
		info->room_ant[ants] = "finished";
		return (1);
	}
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
	while (i < len)
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
	if (ft_strequ(info->room_ant[ants], "finished"))
		return;
	info->room_ant[ants] = ft_take_room(info->path_ant[ants]);
	ft_print(ants, info);
	if (ft_nbrooms_in_path(info->path_ant[ants]) <= 1)
		info->path_ant[ants] = "finished";
	else
		info->path_ant[ants] = ft_sub_path(info->path_ant[ants]);
}

static int	ft_pathcmp(char *path1, char *path2)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = 1;
	while (path1[i] && path2[j] && n < ft_nbrooms_in_path(path1))
	{
		while (path1[i] == path2[j] && path1[i] && path1[i] != '-')
		{
			i++;
			j++;
		}
		if (path1[i] == '-' && path2[j] == '-')
			return (1);
		while (path1[i] && path1[i] != '-')
			i++;
		while (path2[j] && path2[j] != '-')
			j++;
		j++;
		i++;
		n++;
	}
	return (0);
}

static int	ft_opti_path(t_ants *info, char *path, int ants)
{
//check si le chemin est valide est qu'il est optimise pour la fourmis
	int		i;

	i = ants - ants; //i = 0;
	while (info->path_ant[i])
	{
		if (info->path_ant[i] != NULL)
		{
			if (ft_pathcmp(info->path_ant[i], path))
				return (0);
		}
		i++;
	}
	return (1);
}

static void	ft_ant_path(int ants, t_ants *info, char **all_paths)
{
	//essaye de donner le chemin(possible) le plus rapide a la fourmis
	int		i;

	i = 0;
	while (all_paths[i])
	{
		if (ft_opti_path(info, all_paths[i], ants))
		{
			info->path_ant[ants] = ft_strdup(all_paths[i]);
			return ;
		}
		i++;
	}
}

void		ft_algo(t_ants *info, char **all_paths)
{
	int		ants;
	int		over;

	over = 0;
	info->room_ant = (char**)malloc(sizeof(char*) * (info->nb_ant + 1));
	info->path_ant = (char**)malloc(sizeof(char*) * (info->nb_ant + 1));
	while (over != info->nb_ant)
	{
		ants = 0;
		while (ants < info->nb_ant)
		{
			if (info->path_ant[ants] == NULL)
				ft_ant_path(ants, info, all_paths);
			else
			{
				if (ft_finished(ants, info))
					over++;
				else
					ft_moove(ants, info);
			}
			ants++;
		}
		ft_putchar('\n');
	}
}
