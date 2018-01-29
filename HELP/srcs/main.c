/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:03:46 by alecott           #+#    #+#             */
/*   Updated: 2018/01/29 17:17:50 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static void		ft_player_team_s(t_filler *info)
{
	char	*line;

	get_next_line(0, &line);
	if (line[10] == '2')
		info->team = 'X';
	else
		info->team = 'O';
	ft_strdel(&line);
}

static void		ft_mapx(t_filler *info, int i, int j, char *line)
{
	char	*tmp;
	int		x;

	x = 0;
	while (line[j] <= '9' && line[j] >= '0')
		j++;
	tmp = (char*)malloc(sizeof(char) * (j - i + 1));
	while (i < j)
	{
		tmp[x] = line[i];
		i++;
		x++;
	}
	tmp[i] = '\0';
	info->mapx = ft_atoi(tmp);
	ft_strdel(&tmp);
}

static int		ft_mapy(t_filler *info)
{
	char	*line;
	int		i;
	int		j;
	char	*tmp;

	j = 8;
	i = 8;
	get_next_line(0, &line);
	if (line == NULL)
		return (0);
	while (line[j] <= '9' && line[j] >= '0')
		j++;
	tmp = (char*)malloc(sizeof(char) * (j - 7));
	while (i < j)
	{
		tmp[i - 8] = line[i];
		i++;
	}
	tmp[i] = '\0';
	info->mapy = ft_atoi(tmp);
	ft_strdel(&tmp);
	ft_mapx(info, i + 1, j + 1, line);
	ft_strdel(&line);
	return (1);
}

int				main(void)
{
	t_filler	*info;

	info = (t_filler*)malloc(sizeof(t_filler));
	ft_player_team_s(info);
	while (1)
	{
		if (!(ft_mapy(info)))
			break ;
		ft_map(info);
		ft_piece(info);
		if (!(ft_placement(info)))
			break ;
	}
	free(info);
	return (0);
}
