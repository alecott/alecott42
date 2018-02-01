/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:43:25 by alecott           #+#    #+#             */
/*   Updated: 2018/02/01 12:51:02 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int		ft_check2(t_filler *info, int ip, int jp)
{
	int		i;
	int		j;
	int		x;

	x = 0;
	i = 0;
	j = 0;
	while (info->piece[i])
	{
		while (info->piece[i][j] != '\0')
		{
			if (info->piece[i][j] == '*' &&
		info->map[info->y + (i - ip)][info->x + (j - jp)] != info->team
		&& info->map[info->y + (i - ip)][info->x + (j - jp)] != '.')
				return (0);
			else if (info->piece[i][j] == '*' &&
					info->map[info->y + (i - ip)][info->x + (j - jp)]
					== info->team)
				x++;
			j++;
		}
		j = 0;
		i++;
	}
	return (x);
}

static void		dlst_add(t_daewae **queen, t_daewae *uganda)
{
	if (*queen == 0)
	{
		*queen = uganda;
		return ;
	}
	uganda->next = *queen;
	*queen = uganda;
}

static void		ft_check(t_filler *info, t_daewae **d)
{
	t_daewae	*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (info->piece[i])
	{
		while (info->piece[i][j])
		{
			if (info->piece[i][j] == '*' && info->x >= j && info->y >= i &&
					info->mapx - info->x >= info->piecex - j &&
					info->mapy - info->y >= info->piecey - i &&
					ft_check2(info, i, j) == 1)
			{
				tmp = ft_memalloc(sizeof(t_daewae));
				tmp->x = info->x - j;
				tmp->y = info->y - i;
				dlst_add(d, tmp);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static int		ft_choose_wisely(t_filler *info, t_daewae *d)
{
	t_daewae	*tmp;

	if (d == NULL)
		return (0);
	tmp = d;
	while (d->next)
	{
		d = d->next;
		if (ft_score(info, d) < ft_score(info, tmp))
			tmp = d;
	}
	ft_putnbr(tmp->y);
	ft_putchar(' ');
	ft_putnbr(tmp->x);
	ft_putchar('\n');
	return (1);
}

int				ft_placement(t_filler *info)
{
	t_daewae	*d;
	t_daewae	*tmp;
	int			res;

	info->x = 0;
	info->y = 0;
	d = 0;
	while (info->map[info->y])
	{
		while (info->map[info->y][info->x] != '\0')
		{
			if (info->map[info->y][info->x] == info->team)
				ft_check(info, &d);
			info->x = info->x + 1;
		}
		info->x = 0;
		info->y = info->y + 1;
	}
	res = ft_choose_wisely(info, d);
	while (d)
	{
		tmp = d->next;
		ft_memdel((void **)&d);
		d = tmp;
	}
	return (res);
}
