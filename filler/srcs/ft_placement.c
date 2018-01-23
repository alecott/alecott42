/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:43:25 by alecott           #+#    #+#             */
/*   Updated: 2018/01/23 18:25:21 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../filler.h>

static int	ft_check2(t_filler *info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (info->piece[i])
	{
		while (info->piece[i][j])
		{
			if (info->piece[i][j] == '*' && info->map[info->X][info->Y] != '.')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	ft_check(t_filler *info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (info->piece[i])
	{
		while (info->piece[i][j])
		{
			if (info->piece[i][j] == '*' && info->X >= i && info->Y >= j && 
					info->mapX - info->X >= info->pieceX - i &&
					info->mapY - info->Y >= info->pieceY - j && ft_check2(info))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static int	ft_remplissage(t_filler *info, t_daewae *d)
{
	info->X = 0;
	info->Y = 0;
	while (info->map[info->Y])
	{
		while (info->map[info->Y][info->X])
		{
			if (info->map[info->Y][info->X] == '0' && ft_check(info))
			{
//->stocker


				
			}
			info->X++;
		}
		info->X = 0;
		info->Y++;
	}
	return (0);
}

int			ft_placement(t_filler *info)
{
	t_daewae *d;

	d = (t_daewae*)malloc(sizeof(t_daewae));
	if (!(ft_remplissage(info, d)))
	{
		free(d);
		return (0);
	}
	return (1);
}
