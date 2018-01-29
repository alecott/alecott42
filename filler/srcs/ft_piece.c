/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:21:28 by alecott           #+#    #+#             */
/*   Updated: 2018/01/29 17:22:38 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static void		ft_piecex(t_filler *info, int i, int j, char *line)
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
	info->piecex = ft_atoi(tmp);
	ft_strdel(&tmp);
}

static void		ft_piecey(t_filler *info)
{
	char	*line;
	int		i;
	int		j;
	char	*tmp;

	j = 6;
	i = 6;
	get_next_line(0, &line);
	while (line[j] <= '9' && line[j] >= '0')
		j++;
	tmp = (char*)malloc(sizeof(char) * (j - 5));
	while (i < j)
	{
		tmp[i - 6] = line[i];
		i++;
	}
	tmp[i] = '\0';
	info->piecey = ft_atoi(tmp);
	ft_strdel(&tmp);
	ft_piecex(info, i + 1, j + 1, line);
	ft_strdel(&line);
}

void			ft_piece(t_filler *info)
{
	char	*line;
	int		i;

	i = 0;
	ft_piecey(info);
	info->piece = (char**)malloc(sizeof(char*) * info->piecey + 1);
	while (i < info->piecey)
	{
		get_next_line(0, &line);
		info->piece[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	info->piece[i] = NULL;
}
