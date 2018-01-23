/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:03:46 by alecott           #+#    #+#             */
/*   Updated: 2018/01/23 18:25:29 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static void	ft_player_team_s(t_filler *info, int fd)
{
	char	*line;

	get_next_line(fd, &line);
	if (line[10] == '2')
		info->team = 'O';
	else
		info->team = 'X';
	free(line);
}

static void	ft_mapX(t_filler *info, int i, int j, char *line)
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
	info->mapX = ft_atoi(tmp);
	free(tmp);
	free(line);
}


static void	ft_mapY(t_filler *info,  int fd)
{
	char	*line;
	int		i;
	int		j;
	char	*tmp;

	j = 8;
	i = 8;
	get_next_line(fd, &line);
	while (line[j] <= '9' && line[j] >= '0')
		j++;
	tmp = (char*)malloc(sizeof(char) * (j - 7));
	while (i < j)
	{
		tmp[i - 8] = line[i];
		i++;
	}
	tmp[i] = '\0';
	info->mapY = ft_atoi(tmp);
	free(tmp);
	ft_mapX(info, i + 1, j + 1, line);
}

static void	ft_DAE_WAE(t_filler *info)
{
	ft_putstr("mapX: ");
	ft_putnbr(info->mapX);
	ft_putchar('\n');
	ft_putstr("mapY: ");
	ft_putnbr(info->mapY);
	ft_putchar('\n');
	ft_putstr("pieceX: ");
	ft_putnbr(info->pieceX);
	ft_putchar('\n');
	ft_putstr("pieceY: ");
	ft_putnbr(info->pieceY);
	ft_putchar('\n');
	ft_putstr("team: ");
	ft_putchar(info->team);
}

int		main()
{
	t_filler	*info;
	int		fd;

	fd = open("test2", O_RDONLY);
	info = (t_filler*)malloc(sizeof(t_filler));
	ft_player_team_s(info, fd);
//	while (1)
//	{
	ft_mapY(info, fd);
//		if (!(ft_map(info, fd)))
	ft_map(info, fd);
//			return (0);
	ft_piece(info, fd);
//			return (0);
	ft_DAE_WAE(info);
	if (!(ft_placement(info)))
		return (0);
//	}
	free(info);
	return (0);
}
