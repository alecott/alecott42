/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:21:28 by alecott           #+#    #+#             */
/*   Updated: 2018/01/23 14:43:05 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include <stdio.h>

static void	ft_pieceX(t_filler *info, int i, int j, char *line)
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
	info->pieceX = ft_atoi(tmp);
	free(tmp);
	free(line);
}


static void	ft_pieceY(t_filler *info,  int fd)
{
	char	*line;
	int		i;
	int		j;
	char	*tmp;

	j = 6;
	i = 6;
	get_next_line(fd, &line);
	while (line[j] <= '9' && line[j] >= '0')
		j++;
	tmp = (char*)malloc(sizeof(char) * (j - 5));
	while (i < j)
	{
		tmp[i - 6] = line[i];
		i++;
	}
	tmp[i] = '\0';
	info->pieceY = ft_atoi(tmp);
	free(tmp);
	ft_pieceX(info, i + 1, j + 1, line);
}

void	ft_piece(t_filler *info, int fd)
{
	char	*line;
	int		i;

	i = 0;
	ft_pieceY(info, fd);
	info->piece = (char**)malloc(sizeof(char*) * info->pieceY + 1);
	while (i < info->mapY && get_next_line(fd, &line))
	{
		info->piece[i] = line;
		ft_strdel(&line);
		ft_putstr(info->piece[i]);
		ft_putchar('\n');
		i++;
	}
	info->piece[i] = NULL;
}
